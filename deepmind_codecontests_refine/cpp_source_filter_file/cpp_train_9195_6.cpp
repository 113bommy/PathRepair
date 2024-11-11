#include <bits/stdc++.h>
using namespace std;
const int N = 22, M = 102;
int n, k, t, cnt;
pair<int, long long> e[M];
void dfs(int i, int second, int val, long long mask) {
  if (cnt >= t || i == k) return;
  if (val + e[i].first > second) return;
  if (!(e[i].second & mask)) {
    ++cnt;
    dfs(i + 1, second, val + e[i].first, mask | e[i].second);
  }
  dfs(i + 1, second, val, mask);
}
int main() {
  cin >> n >> k >> t;
  for (int i = 0, h, first; i < k; ++i) {
    cin >> h >> first >> e[i].first;
    e[i].second |= (1 << h + n) | (1 << first);
  }
  sort(e, e + k);
  int lo = 0, hi = 100000;
  while (lo < hi) {
    int second = lo + hi >> 1;
    cnt = 1;
    dfs(0, second, 0, 0);
    if (cnt >= t)
      hi = second;
    else
      lo = second + 1;
  }
  cout << lo << endl;
  return 0;
}
