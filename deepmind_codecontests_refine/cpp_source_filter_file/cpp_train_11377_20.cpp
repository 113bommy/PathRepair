#include <bits/stdc++.h>
using namespace std;
void update(vector<int> &fenwick, int index, int value, bool type) {
  while (index < fenwick.size()) {
    if (type)
      fenwick[index] = max(fenwick[index], value);
    else
      fenwick[index] = min(fenwick[index], value);
    index += index & -index;
  }
}
int read(vector<int> &fenwick, int index, bool type) {
  int best = (type ? -1 : (int)fenwick.size() - 1);
  while (index > 0) {
    if (type)
      best = max(best, fenwick[index]);
    else
      best = min(best, fenwick[index]);
    index -= index & -index;
  }
  return best;
}
inline int flip(int i, int n) { return n + 1 - i; }
int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<long long> internal(1 + n);
  for (int i = 1; i <= n; ++i) {
    internal[i] = internal[i - 1] + i * (i + 1LL) / 2;
  }
  int cur = 0;
  vector<int> left(n, -1);
  vector<int> fenwick(1 + n, -1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      for (int j = 1; j <= cur; ++j) update(fenwick, flip(j, n), i - j, true);
      cur = 0;
    } else {
      ++cur;
      left[i] = read(fenwick, flip(cur, n), true);
    }
  }
  cur = 0;
  vector<int> right(n, n);
  fenwick = vector<int>(1 + n, n);
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '0') {
      for (int j = 1; j <= cur; ++j) update(fenwick, flip(j, n), i + j, false);
      cur = 0;
    } else {
      ++cur;
      right[i] = read(fenwick, flip(cur + 1, n), false);
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    while (i < n && s[i] == '0') ++i;
    int first = i;
    while (i < n && s[i] == '1') ++i;
    int last = i - 1;
    if (last < first) break;
    int len = last - first + 1;
    ans += internal[len];
    ans += (first - left[last]) * (long long)(right[first] - last) * len;
    ans -= len;
    for (int start = first + 1; start <= last; ++start) {
      ans += (right[start] - 1 - last) * (last - start + 1);
    }
    for (int finish = last - 1; finish >= first; --finish) {
      ans += (first - 1 - left[finish]) * (finish - first + 1);
    }
  }
  cout << ans << endl;
  return 0;
}
