#include <bits/stdc++.h>
using namespace std;
int n, m, t[300005][10], idx[1001301];
pair<long long, int> check(int M) {
  for (int i = 0; i < (1 << m); i++) idx[i] = 0;
  for (int i = 1; i <= n; i++) {
    int val = 0;
    for (int j = 1; j <= m; j++) val = val * 2 + (t[i][j] >= M ? 1 : 0);
    idx[val] = i;
  }
  for (int i = 0; i < (1 << m); i++) {
    if (!idx[i]) continue;
    for (int j = 0; j < (1 << m); j++) {
      if (!idx[j]) continue;
      if ((i | j) == (1 << m) - 1) return {idx[i], idx[j]};
    }
  }
  return {0, 0};
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> t[i][j];
    }
  }
  int l = 0;
  int p = 1e9;
  int mid = (l + p + 1) / 2;
  while (l != p) {
    pair<long long, int> kek = check(mid);
    if (kek.first != 0)
      l = mid;
    else
      p = mid - 1;
    mid = (l + p + 1) / 2;
  }
  pair<long long, int> res = check(mid);
  cout << res.first << " " << res.second << "\n";
}
