#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 69;
const int lN = 19;
int a[N];
tuple<int, int, int> Q[N];
int adj[lN][lN];
bool ans[N];
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) cin >> a[i + 1];
  for (int i = 0; i < lN; i++)
    for (int j = 0; j < lN; j++) adj[i][j] = N;
  for (int i = 0; i < q; i++) {
    cin >> get<0>(Q[i]) >> get<1>(Q[i]);
    get<2>(Q[i]) = i;
  }
  sort(Q, Q + q);
  int qi = q - 1;
  for (int i = N - 1; i >= 0; i--) {
    int x = a[i + 1];
    for (int j = 0; j < lN; j++)
      if (x & (1 << j))
        for (int k = 0; k < lN; k++)
          if (x & (1 << k)) adj[j][k] = i + 1;
    for (int j = 0; j < lN; j++)
      if (x & (1 << j))
        for (int k = 0; k < lN; k++)
          if (x & (1 << k))
            for (int l = 0; l < lN; l++) adj[j][l] = min(adj[j][l], adj[k][l]);
    while (get<0>(Q[qi]) == i + 1) {
      int l, r, nq;
      tie(l, r, nq) = Q[qi];
      for (int j = 0; j < lN; j++)
        if (x & (1 << j))
          for (int k = 0; k < lN; k++)
            if (a[r] & (1 << k))
              if (adj[j][k] <= r) {
                ans[nq] = 1;
                goto ok;
              }
    ok:;
      if (!qi--) goto end;
    }
  }
end:;
  for (int i = 0; i < q; i++) cout << (ans[i] ? "Shi\n" : "Fou\n");
}
