#include <bits/stdc++.h>
using namespace std;
int Head[2000010], Next[2000010], Go[2000010], Cnt = 0;
struct flow {
  int Head[250010], Next[2000010], Go[2000010], Cnt;
  long long Val[2000010], Fl[250010];
  int Am[250010], H[250010], Pr[250010], Nw[250010];
  flow() { Cnt = 1, memset(Head, 0, sizeof Head); }
  void addedge(int a, int b, long long c) {
    Go[++Cnt] = b;
    Next[Cnt] = Head[a];
    Head[a] = Cnt;
    Val[Cnt] = c;
  }
  long long getflow(int S, int TT, int tot) {
    int first = S;
    long long f = 1e18;
    Am[0] = tot;
    long long ans = 0;
    while (H[first] <= tot) {
      if (!Nw[first]) Nw[first] = Head[first];
      int flag = 0;
      for (int &T = Nw[first]; T; T = Next[T])
        if (Val[T] && H[Go[T]] == H[first] - 1) {
          flag = 1, Pr[Go[T]] = T ^ 1;
          Fl[first] = f, f = min(f, Val[T]);
          first = Go[T];
          if (first == TT) {
            ans += f;
            while (first != S)
              Val[Pr[first]] += f, Val[Pr[first] ^ 1] -= f,
                  first = Go[Pr[first]];
            f = 1e18;
          }
          break;
        }
      if (!flag) {
        int mn = tot;
        for (int T = Head[first]; T; T = Next[T])
          if (Val[T] && H[Go[T]] < mn) mn = H[Go[T]], Nw[first] = T;
        if (!--Am[H[first]]) break;
        Am[H[first] = mn + 1]++;
        if (first != S) {
          first = Go[Pr[first]];
          f = Fl[first];
        }
      }
    }
    return ans;
  }
} qwq;
int n, m, Dis[105][105], XA[250010], AA[250010], FA[250010], PA[250010],
    XB[250010], DB[250010], GB[250010];
long long Ans[100010];
vector<pair<long long, long long> > V[105];
int main() {
  scanf("%d%d", &n, &m);
  memset(Dis, 63, sizeof Dis);
  for (int i = 1; i <= n; i++) Dis[i][i] = 0;
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    Dis[a][b] = 1, Dis[b][a] = 1;
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 1; k <= n; k++)
        Dis[j][k] = min(Dis[j][k], Dis[j][i] + Dis[i][k]);
  int s, b, k;
  scanf("%d%d%d", &s, &b, &k);
  for (int i = 1; i <= s; i++)
    scanf("%d%d%d%d", &XA[i], &AA[i], &FA[i], &PA[i]);
  for (int i = 1; i <= n; i++)
    V[i].push_back(pair<long long, long long>(-1e18, -1e18));
  for (int i = 1; i <= b; i++) {
    int first, d, g;
    scanf("%d%d%d", &first, &d, &g);
    V[first].push_back(pair<long long, long long>(d, g));
  }
  for (int i = 1; i <= n; i++) {
    sort(V[i].begin(), V[i].end());
    for (int j = 1; j < V[i].size(); j++)
      V[i][j].second = max(V[i][j].second, V[i][j - 1].second);
  }
  for (int i = 1; i <= s; i++) {
    long long ans = -1e18;
    for (int j = 1; j <= n; j++)
      if (Dis[XA[i]][j] <= FA[i])
        ans =
            max(ans,
                V[j][lower_bound(V[j].begin(), V[j].end(),
                                 pair<long long, long long>(AA[i] + 1, -1e18)) -
                     V[j].begin() - 1]
                    .second);
    Ans[i] = ans - PA[i];
  }
  while (k--) {
    int s1, s2;
    scanf("%d%d", &s1, &s2);
    qwq.addedge(s1, s2, 1e18);
    qwq.addedge(s2, s1, 0);
  }
  long long ans = 0;
  for (int i = 1; i <= s; i++)
    if (Ans[i] > 0)
      ans += Ans[i], qwq.addedge(s + 1, i, Ans[i]), qwq.addedge(i, s + 1, 0);
    else
      qwq.addedge(i, s + 2, -Ans[i]), qwq.addedge(s + 2, i, 0);
  printf("%lld\n", ans - qwq.getflow(s + 1, s + 2, s + 2));
  return 0;
}
