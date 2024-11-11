#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200020;
const int MAXM = 1000010;
const int INF = 1012345678;
int n, m;
struct Interval {
  int lower, upper;
  Interval() {}
  Interval(int lower, int upper) : lower(lower), upper(upper) {}
  int pos() const {
    if (lower == 1) return 1;
    if (upper == n) return n;
    return (lower + upper) >> 1;
  }
  int length() const {
    if (lower == 1 && upper == n) return INF;
    if (lower == 1) return upper;
    if (upper == n) return n - lower + 1;
    return ((upper - lower) >> 1) + 1;
  }
  bool operator<(const Interval &rhs) const {
    return length() > rhs.length() ||
           (length() == rhs.length() && lower < rhs.lower);
  }
};
bool occupy[MAXN];
int location[MAXM], lleft[MAXN], rright[MAXN];
set<Interval> intervalSet;
void insertInterval(int lower, int upper) {
  intervalSet.insert(Interval(lower, upper));
  lleft[upper] = lower;
  rright[lower] = upper;
}
void removeInterval(int lower, int upper) {
  intervalSet.erase(Interval(lower, upper));
  lleft[upper] = rright[lower] = 0;
}
int main() {
  scanf("%d%d", &n, &m);
  insertInterval(1, n);
  for (int o = 0; o < m; o++) {
    int t, idx;
    scanf("%d%d", &t, &idx);
    if (t == 1) {
      Interval interval = *intervalSet.begin();
      int lower = interval.lower, upper = interval.upper;
      removeInterval(lower, upper);
      int pos = interval.pos();
      printf("%d\n", pos);
      location[idx] = pos;
      occupy[pos] = true;
      if (lower == upper) continue;
      if (lower == pos) {
        insertInterval(pos + 1, upper);
      } else if (pos == upper) {
        insertInterval(lower, pos - 1);
      } else {
        insertInterval(lower, pos - 1);
        insertInterval(pos + 1, upper);
      }
    } else {
      int pos = location[idx];
      occupy[pos] = false;
      int lower = pos, upper = pos;
      if (pos - 1 > 0 && !occupy[pos - 1]) {
        lower = lleft[pos - 1];
        removeInterval(lleft[pos - 1], pos - 1);
      }
      if (pos + 1 <= n && !occupy[pos + 1]) {
        upper = rright[pos + 1];
        removeInterval(pos + 1, rright[pos + 1]);
      }
      insertInterval(lower, upper);
    }
  }
  return 0;
}
