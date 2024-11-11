#include <bits/stdc++.h>
const uint32_t MAX_N = 1.01e5;
const uint32_t BUCKET_SIZE = 169;
const uint32_t MAX_BUCK = MAX_N / BUCKET_SIZE;
inline int64_t ceil_r(int64_t n, int64_t d) {
  if (d < 0) {
    n *= -1;
    d *= -1;
  }
  if (n < 0) {
    return n / d;
  } else {
    return (n + d - 1) / d;
  }
}
struct Line {
  int64_t a, b;
  Line(int64_t a = 0, int64_t b = 0) : a(a), b(b) {}
  int64_t operator()(int64_t x) const { return a * x + b; }
  static int64_t intersect_x(const Line &l1, const Line &l2) {
    int64_t num = l2.b - l1.b;
    int64_t denum = l1.a - l2.a;
    return ceil_r(num, denum);
  }
};
uint32_t priceCnt[MAX_N + BUCKET_SIZE];
struct Bucket {
  uint32_t start, len;
  uint32_t size;
  std::vector<std::pair<Line, int64_t>> lines;
  Bucket() : start(0), len(BUCKET_SIZE), size(0) {}
  void recalc() {
    std::vector<Line> tempLines(len);
    size = 0;
    for (uint32_t i = 0; i < len; i++) {
      int64_t j = start + len - i - 1;
      size += priceCnt[j];
      tempLines[j - start] = Line(j, size * j);
    }
    lines.clear();
    for (uint32_t i = 0; i < tempLines.size(); i++) {
      while (!lines.empty()) {
        int64_t x = Line::intersect_x(lines.back().first, tempLines[i]);
        if (x <= lines.back().second) {
          lines.pop_back();
        } else {
          break;
        }
      }
      int64_t startX = 0;
      if (!lines.empty()) {
        startX = Line::intersect_x(lines.back().first, tempLines[i]);
      }
      if (startX < 2 * MAX_N) {
        lines.push_back({tempLines[i], startX});
      }
    }
  }
  std::pair<int64_t, int64_t> best_val(int64_t x) {
    uint32_t l = 0;
    uint32_t h = lines.size();
    while (h - l > 1) {
      uint32_t m = (h + l) / 2;
      if (lines[m].second <= x) {
        l = m;
      } else {
        h = m;
      }
    }
    return {lines[l].first(x), lines[l].first.a};
  }
};
Bucket buckets[MAX_BUCK];
struct Person {
  uint32_t a, b;
  uint32_t bucket() const { return a / BUCKET_SIZE; }
  friend bool operator<(const Person &a, const Person &b) { return a.b < b.b; }
};
std::vector<Person> people;
int64_t adPrice;
uint32_t maxBanner;
void input() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  uint32_t peopleCnt;
  std::cin >> peopleCnt >> adPrice;
  people.resize(peopleCnt);
  maxBanner = 0;
  for (Person &i : people) {
    std::cin >> i.a >> i.b;
    maxBanner = std::max(maxBanner, i.b);
  }
  std::sort(people.begin(), people.end());
}
void init_buckets() {
  for (uint32_t i = 0; i < MAX_BUCK; i++) {
    buckets[i].start = i * BUCKET_SIZE;
    buckets[i].recalc();
  }
}
std::pair<int64_t, int64_t> calc() {
  std::pair<int64_t, int64_t> ans = {0, 0};
  uint32_t curCnt = 0;
  for (uint32_t i = MAX_BUCK - 1; i < MAX_BUCK; i--) {
    auto curAns = buckets[i].best_val(curCnt);
    ans = std::max(ans, curAns);
    curCnt += buckets[i].size;
  }
  return ans;
}
int main() {
  input();
  init_buckets();
  uint32_t peopleI = 0;
  int64_t curPeople = people.size();
  for (uint32_t i = 0; i <= 1 + maxBanner; i++) {
    while ((peopleI < people.size()) && (people[peopleI].b < i)) {
      uint32_t a = people[peopleI].a;
      priceCnt[a]++;
      buckets[a / BUCKET_SIZE].recalc();
      peopleI++;
      curPeople--;
    }
    int64_t adRevenue = curPeople * i * adPrice;
    auto ans = calc();
    std::cout << ans.first + adRevenue << " " << ans.second << "\n";
  }
}
