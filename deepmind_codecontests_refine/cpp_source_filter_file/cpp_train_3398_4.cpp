#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
int n;
long long p[20];
vector<long long> s[2];
void dfs(int k, int L, int R, long long v) {
  s[k].push_back(v);
  for (int i = L; i <= R; ++i)
    if (inf / p[i] >= v) dfs(k, i, R, v * p[i]);
}
long long check(long long v) {
  long long ret = 0;
  int j = 0;
  for (int i = s[0].size() - 1; i >= 0; --i) {
    while (j < s[1].size() && v / s[0][i] >= s[1][j]) j++;
    ret += j;
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) cin >> p[i];
  dfs(0, 1, min(6, n), 1);
  dfs(1, min(6, n) + 1, n, 1);
  sort(s[0].begin(), s[0].end());
  sort(s[1].begin(), s[1].end());
  long long m;
  cin >> m;
  long long L = 1, R = inf, mid;
  long long ans = 1;
  while (L < R - 1) {
    mid = (L + R) >> 1;
    if (check(mid) >= m)
      R = mid;
    else
      L = mid;
  }
  cout << R;
  return 0;
}
