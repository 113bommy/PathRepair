#include <bits/stdc++.h>
#pragma warning(disable : 4244 4267 4018 4996 4800)
using namespace std;
istream& in = cin;
ostream& out = cout;
struct rmq {
  rmq(int size) : v(size, -1) {
    size_t ofs = 1;
    for (size_t const size = v.size(); ofs < size; ofs <<= 1)
      ;
    v.resize(2 * ofs, -1);
  }
  int operator()(size_t lo, size_t hi) const {
    size_t const ofs = v.size() / 2;
    lo += ofs;
    hi += ofs;
    int best = -1;
    while (lo > 0 && lo <= hi) {
      best = max(best, max(v[hi], v[lo]));
      hi--;
      hi >>= 1;
      lo++;
      lo >>= 1;
    }
    return best;
  }
  void update(size_t pos, int val) {
    size_t const ofs = v.size() / 2;
    pos += ofs;
    v[pos] = val;
    for (pos >>= 1; pos >= 1; pos >>= 1)
      v[pos] = max(v[pos * 2], v[pos * 2 + 1]);
  }
  vector<int> v;
};
struct back_t {
  int x;
  int y;
};
int main() {
  int n;
  in >> n;
  vector<int> v(n);
  for (int i = 0; i < n; ++i) in >> v[i];
  vector<int> sorted = v;
  sort((sorted).begin(), (sorted).end());
  vector<int> next(n), index(n, -1);
  for (int i = n - 1; i >= 0; --i) {
    int idx =
        lower_bound((sorted).begin(), (sorted).end(), v[i]) - sorted.begin();
    next[i] = index[idx];
    index[idx] = i;
  }
  vector<int> left(n, -1);
  std::vector<back_t> back(n);
  rmq q(n);
  for (int i1 = 0; i1 < n; ++i1) {
    int i2 = next[i1];
    int i3 = i2 != -1 ? next[i2] : -1;
    int i4 = i3 != -1 ? next[i3] : -1;
    if (i1 < i2 && i2 < i3 && i3 < i4) {
      left[i4] = i1;
      back[i4].x = v[i1];
      back[i4].y = v[i1];
    }
  }
  for (int i = 0; i < n; ++i) {
    int j = next[i];
    if (j == -1) continue;
    int x = q(i + 1, j - 1);
    if (x != -1 && x > left[j]) {
      left[j] = x;
      back[j].x = v[x];
      back[j].y = v[i];
    }
    q.update(j, i);
  }
  vector<int> res(n), prev(n, -1);
  for (int i = 0; i < n; ++i) {
    if (i) {
      res[i] = res[i - 1];
      prev[i] = i - 1;
    }
    int t = left[i];
    if (t != -1 && res[i] < (t ? res[t - 1] : 0) + 1) {
      res[i] = (t ? res[t - 1] : 0) + 1;
      prev[i] = t - 1;
    }
  }
  vector<int> result;
  for (int cur = n - 1; cur != -1; cur = prev[cur]) {
    if (prev[cur] != cur - 1) {
      result.push_back(back[cur].y);
      result.push_back(back[cur].x);
      result.push_back(back[cur].y);
      result.push_back(back[cur].x);
    }
  }
  reverse((result).begin(), (result).end());
  out << result.size() << "\n";
  copy((result).begin(), (result).end(), ostream_iterator<int>(out, " "));
  return 0;
}
