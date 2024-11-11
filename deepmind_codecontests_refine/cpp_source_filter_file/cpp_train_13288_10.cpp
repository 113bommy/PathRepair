#include <bits/stdc++.h>
using namespace std;
const int mod = 1E9 + 7;
const int maxn = 1E6 + 77;
struct Node {
  int s, d, c;
  int last() { return (d == -1) ? (s) : (s + d * (c - 1)); }
} G[maxn], aux[maxn];
int cg = 0, caux = 0;
char SS[maxn], S[maxn];
int L;
long long dp[maxn], F[maxn];
int main() {
  scanf("%s", SS);
  int l = strlen(SS);
  if (l & 1) {
    printf("0\n");
    return 0;
  }
  for (int i = 0, j = l - 1; i < j; ++i, --j) {
    S[++L] = SS[i];
    S[++L] = SS[j];
  }
  dp[0] = 1;
  for (int i = 2; i <= L; ++i) {
    caux = 0;
    for (int g = 0; g < cg; ++g) {
      --G[g].s;
      if (S[i] == S[G[g].s]) {
        if (G[g].c >= 2) {
          int s = G[g].s;
          G[g].s += G[g].d;
          G[g].c--;
          aux[caux] = (Node){s, caux ? (s - aux[caux - 1].last()) : -1, 1};
          caux++;
          aux[caux++] = G[g];
        } else {
          aux[caux] =
              (Node){G[g].s, caux ? (G[g].s - aux[caux - 1].last()) : -1, 1};
          caux++;
        }
      }
    }
    if (S[i] == S[i - 1]) {
      aux[caux] = (Node){i - 1, caux ? (i - 1 - aux[caux - 1].last()) : -1, 1};
      caux++;
    }
    cg = 0;
    if (caux) {
      assert(aux[0].c > 0);
      G[cg++] = aux[0];
    }
    for (int g = 1; g < caux; ++g) {
      assert(aux[g].c > 0);
      assert(G[cg - 1].last() + aux[g].d == aux[g].s);
      if (aux[g].d == G[cg - 1].d)
        G[cg - 1].c += aux[g].c;
      else
        G[cg++] = aux[g];
    }
    for (int g = 0; g < cg; ++g) {
      assert(G[g].c > 0);
      assert((G[g].c == 1) || ((G[g].d & 1) == 0));
      assert(((i - G[g].s) & 1) == 1);
      if (G[g].c == 1) {
        dp[i] += dp[G[g].s - 1];
        if (dp[i] >= mod) dp[i] -= mod;
      } else {
        if (G[g].c == 2) {
          F[G[g].s - G[g].d] = dp[G[g].s - 1];
        }
        dp[i] += F[G[g].s - G[g].d];
        if (dp[i] >= mod) dp[i] -= mod;
        dp[i] += dp[G[g].last() - 1];
        if (dp[i] >= mod) dp[i] -= mod;
        F[G[g].s - G[g].d] += dp[G[g].last() - 1];
        if (F[G[g].s - G[g].d] >= mod) F[G[g].s] -= mod;
      }
    }
  }
  int ans = dp[L];
  printf("%d\n", ans);
}
