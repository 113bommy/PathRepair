#include <bits/stdc++.h>
using namespace std;
vector<int> Cnt[2005];
int need[2005][2005];
int main() {
  int n, k, ans = 0;
  cin >> n >> k;
  if (k == 1) {
    printf("%d\n", n);
    return 0;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (!(i % j)) Cnt[i].push_back(j);
  for (int i = 1; i <= n; i++) need[0][i] = 1;
  for (int c = 1; c < k; c++)
    for (int i = 1; i <= n; i++) {
      int len = Cnt[i].size();
      for (int j = 0; j < len; j++)
        need[c][Cnt[i][j]] = (need[c][Cnt[i][j]] + need[c - 1][i]) % 1000000007;
    }
  for (int i = 1; i <= n; i++) ans = (ans + need[k - 1][i]) % 1000000007;
  printf("%d\n", ans);
  return 0;
}
