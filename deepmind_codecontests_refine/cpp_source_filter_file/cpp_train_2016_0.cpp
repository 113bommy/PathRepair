#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int n, p, x, tot, pos[35], id[35];
bitset<50100> dp[35][35], ff[35][35];
vector<int> ans;
void dfs(int i, int j, int k) {
  if (i == 0) return;
  if (!ff[i][j][k])
    dfs(i - 1, j, k);
  else {
    ans.push_back(pos[id[i]]);
    for (int y = 0; y < p; y++)
      if (dp[i - 1][j ^ id[i]][y] &&
          (y * (id[i] < 10 ? 10 : 100) + id[i]) % p == k) {
        dfs(i - 1, j ^ id[i], y);
        return;
      }
  }
}
int main() {
  scanf("%d%d", &n, &p);
  tot = 0;
  dp[0][0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &x);
    if (x < 32) {
      tot++;
      pos[x] = i;
      id[tot] = x;
      for (int j = 0; j < 32; j++)
        for (int k = 0; k < p; k++)
          if (dp[tot - 1][j][k]) {
            int kk = x < 10 ? k * 10 + x : k * 100 + x;
            kk %= p;
            dp[tot][j ^ x][kk] = 1;
            ff[tot][j ^ x][kk] = 1;
            if ((j ^ x) == 0 && kk == 0) {
              dfs(tot, 0, 0);
              puts("YES");
              printf("%d\n", ((int)(ans).size()));
              for (int p = ((int)(ans).size()) - 1; p >= 0; p--)
                printf("%d ", ans[p]);
              return 0;
            }
            dp[tot][j][k] = 1;
            ff[tot][j][k] = 0;
          }
    }
  }
  puts("NO");
}
