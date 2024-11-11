#include <bits/stdc++.h>
using namespace std;
int n;
int v[16];
int adj[16];
long long int dp[1 << 16];
long long int go(int a, int b) {
  int i, j, m;
  long long int temp;
  if (a == n) {
    return 1LL;
  }
  long long int &best = dp[b];
  if (best != -1LL) {
    return best;
  }
  best = 0LL;
  for (i = (0); i < (n); i++) {
    if (v[a] == -1 || v[a] == i) {
      if (!(b & (1 << i)) && (b & (adj[i])) == adj[i]) {
        temp = go(a + 1, b | (1 << i));
        best += temp;
      }
    }
  }
  return best;
}
void imprimir(long long int y) {
  int i, j;
  long long int temp;
  int res[16];
  memset(v, -1, sizeof v);
  memset(dp, -1, sizeof dp);
  temp = go(0, 0);
  if (temp < y) {
    printf("The times have changed\n");
    return;
  }
  for (i = (0); i < (n); i++) {
    for (j = (0); j < (n); j++) {
      if (v[j] == -1) {
        v[j] = i;
        res[i] = j + 1;
        memset(dp, -1, sizeof dp);
        temp = go(0, 0);
        if (temp >= y) {
          break;
        }
        y -= temp;
        v[j] = -1;
      }
    }
  }
  for (i = (0); i < (n); i++) {
    printf("%d%s", res[i], (i == n - 1) ? "\n" : " ");
  }
}
int main() {
  int i, a, b, m;
  long long int y;
  memset(adj, 0, sizeof adj);
  scanf("%d%lld%d", &n, &y, &m);
  for (i = (0); i < (m); i++) {
    scanf("%d%d", &a, &b);
    adj[b - 1] |= (1 << (a - 1));
  }
  imprimir(y - 2001LL + 1LL);
  return 0;
}
