#include <bits/stdc++.h>
using namespace std;
int n;
int ind[60 + 5];
int a[60 + 5];
struct DSU {
  int fa[60 + 5];
  int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
  void merge(int x, int y) { fa[find(x)] = find(y); }
  void ini(int n) {
    for (int i = 1; i <= n; i++) fa[i] = i;
  }
} D;
vector<int> B[60 + 5];
int sta[60 + 5], to[(1 << 15) + 5], dp[(1 << 15) + 5][60 + 5];
int C[60 + 5][60 + 5];
void ini(int n) {
  C[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++)
      C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % 1000000007;
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  D.ini(n);
  ini(n);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[j] % a[i] == 0) {
        D.merge(i, j);
        ind[j]++;
      }
    }
  }
  for (int i = 1; i <= n; i++) B[D.find(i)].push_back(i);
  int ans = 1;
  int len = 0;
  for (int r = 1; r <= n; r++) {
    if ((int)B[r].size() <= 1) continue;
    vector<int> S;
    for (int x : B[r])
      if (!ind[x]) S.push_back(x);
    int cnts = S.size(), cntt = 0;
    memset(to, 0, sizeof(to));
    memset(dp, 0, sizeof(dp));
    for (int x : B[r]) {
      if (ind[x]) {
        cntt++;
        for (int j = 0; j < cnts; j++)
          if (a[x] % a[S[j]] == 0) sta[x] |= (1 << j);
        to[sta[x]]++;
      }
    }
    for (int i = 0; i < cnts; i++) {
      for (int j = 0; j < (1 << cnts); j++) {
        if (!(j & (1 << i))) to[j | (1 << i)] += to[j];
      }
    }
    dp[0][0] = 1;
    for (int i = 0; i < (1 << cnts); i++) {
      for (int j = 0; j < cntt; j++) {
        if (j < to[i])
          dp[i][j + 1] =
              (dp[i][j + 1] + 1ll * dp[i][j] * (to[i] - j) % 1000000007) %
              1000000007;
        for (int x : B[r]) {
          if (ind[x] && ((sta[x] & i) != sta[x]) &&
              ((sta[x] & i) != 0 || i == 0))
            dp[i | sta[x]][j + 1] =
                (dp[i | sta[x]][j + 1] + dp[i][j]) % 1000000007;
        }
      }
    }
    ans = 1ll * ans * dp[(1 << cnts) - 1][cntt] % 1000000007 *
          C[cntt + len - 1][cntt - 1] % 1000000007;
    len += cntt - 1;
  }
  printf("%d\n", ans);
}
