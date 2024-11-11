#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;
const int MX = 1048576;
int smaller[MX], remain[MX];
inline void add(int *bit, int i, int x) {
  for (++i; i < MX; i += i & -i) bit[i] += x;
}
inline int sum(int *bit, int i) {
  int res = 0;
  for (++i; i; i -= i & -i) res += bit[i];
  return res;
}
inline int find(int *bit, int k) {
  int lo = 0, hi = MX, mid;
  while (lo + 1 < hi) {
    mid = (lo + hi) / 2;
    if (bit[mid] >= k)
      hi = mid;
    else
      lo = mid, k -= bit[mid];
  }
  return hi - 1;
}
long long ans;
int n, m, a[MX], b[MX];
bool isremain[MX];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)n; i++) scanf("%d", a + i);
  for (int i = 0; i < (int)m; i++) scanf("%d", b + i), isremain[b[i]] = 1;
  priority_queue<pair<int, int> > q_remain, q_notremain;
  for (int i = 0; i < (int)n; i++) {
    if (!isremain[a[i]])
      q_notremain.push(make_pair(-a[i], i));
    else
      q_remain.push(make_pair(-a[i], i));
  }
  for (int i = 0; i < (int)n; i++) add(remain, i, 1);
  while (!q_notremain.empty()) {
    int cur = -q_notremain.top().first;
    int idx = q_notremain.top().second;
    q_notremain.pop();
    while (q_remain.size() && -q_remain.top().first < cur) {
      add(smaller, q_remain.top().second, 1);
      q_remain.pop();
    }
    int cur_cnt = sum(smaller, idx);
    int left = find(smaller, cur_cnt);
    int right = min(find(smaller, cur_cnt + 1), n);
    if (a[left] < a[idx]) left++;
    ans += sum(remain, right - 1) - sum(remain, left - 1);
    add(remain, idx, -1);
  }
  cout << ans << endl;
  return 0;
}
