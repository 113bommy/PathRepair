#include <bits/stdc++.h>
using namespace std;
vector<int> e[40 + 5];
long long nb[40 + 5];
int clr[40 + 5], bip = 1;
void dfs(int now) {
  for (auto v : e[now]) {
    if (clr[v] == 0) {
      clr[v] = 3 - clr[now];
      dfs(v);
    } else if (clr[v] == clr[now])
      bip = 0;
  }
}
int cnt[1 << 20];
bool ok[1 << 20];
void fwt(int a[], int N) {
  for (int j = 1; j < N; j <<= 1)
    for (int i = 0; i <= N - 1; i++)
      if (i & j) a[i] += a[i ^ j];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  int N1 = n / 2, N2 = n - N1, iso = 0;
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    e[x].push_back(y);
    e[y].push_back(x);
    nb[x] |= 1ll << y;
    nb[y] |= 1ll << x;
  }
  for (int i = 0; i <= n - 1; i++) iso += nb[i] == 0;
  int CC = 0;
  for (int i = 0; i <= n - 1; i++)
    if (clr[i] == 0) {
      clr[i] = 1;
      dfs(i);
      CC++;
    }
  long long ind = 0;
  cnt[0] = 1;
  for (int S = 1; S <= (1 << N2) - 1; S++) {
    int v = __builtin_ctz(S) + N1;
    if (cnt[S ^ (1 << (v - N1))] && (S & (nb[v] >> N1)) == 0) cnt[S] = 1;
  }
  fwt(cnt, 1 << N2);
  ok[0] = 1;
  for (int S = 0; S <= (1 << N1) - 1; S++) {
    if (S) {
      int v = __builtin_ctz(S);
      if (ok[S ^ (1 << v)] && (S & nb[v]) == 0) ok[S] = 1;
    }
    if (ok[S]) {
      long long T = 0;
      for (int i = 0; i <= N1 - 1; i++)
        if (S & (1 << i)) T |= nb[i];
      T = (T >> N1) ^ ((1 << N2) - 1);
      ind += cnt[T];
    }
  }
  long long ans = (1ll << n) - (1ll << CC) - ind * 2 + (1ll << iso + 1) +
                  bip * (1ll << CC) - (m == 0 ? 1ll << n : 0);
  printf("%I64d\n", ans);
  return 0;
}
