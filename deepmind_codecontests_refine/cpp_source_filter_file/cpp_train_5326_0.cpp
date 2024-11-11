#include <bits/stdc++.h>
using namespace std;
int n, q, Deg[300010], Dep[300010], mxdep = 0;
pair<int, int> Fa1[300010], Ch1[300010], Ch2[300010];
int Bel[300010], Lim[300010], Fa2[300010];
int Real[300010][26], Self[300010][26], qwq[300010][26], Sum[300010],
    Sumqwq[300010], num_1 = 0;
int DFS(int first, int dep) {
  Dep[first] = dep, mxdep = max(mxdep, dep);
  if (Ch1[first].first) Ch2[first].first = DFS(Ch1[first].first, dep + 1);
  if (Ch1[first].second) Ch2[first].second = DFS(Ch1[first].second, dep + 1);
  if (Deg[first] == 0 || Deg[first] == 2) {
    if (Deg[first] == 2)
      Fa2[Ch2[first].first] = first, Fa2[Ch2[first].second] = first;
    return Bel[first] = first;
  } else
    return Bel[first] = Ch1[first].first;
}
int chg(int first) { return first == '?' ? -1 : first - 'a'; }
void add(int first, int v) {
  int w = Fa1[first].second;
  first = Bel[first];
  Self[first][w] += v;
  Real[first][w] += v;
  for (int i = Fa2[first]; i; i = Fa2[i]) {
    if (Sumqwq[i] > mxdep - Dep[i]) num_1--;
    Sumqwq[i] -= qwq[i][w];
    qwq[i][w] = max(Real[Ch2[i].first][w], Real[Ch2[i].second][w]);
    Real[i][w] = qwq[i][w] + Self[i][w];
    if ((Sumqwq[i] += qwq[i][w]) > mxdep - Dep[i]) num_1++;
  }
}
void getans() {
  if (num_1) {
    puts("Fou");
    return;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) ans += (i + 1) * Real[1][i];
  ans += (mxdep - Sumqwq[1]) * 13 * 27;
  printf("Shi %d\n", ans);
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 2; i <= n; i++) {
    int a;
    char ch[7];
    scanf("%d%s", &a, ch);
    Fa1[i] = pair<int, int>(a, chg(ch[0]));
    if (!Ch1[a].first)
      Ch1[a].first = i;
    else
      Ch1[a].second = i;
    Deg[a]++;
  }
  DFS(1, 0);
  if (Deg[1] == 1) {
    Deg[1] = 2, Ch2[1].second = 0, Fa2[Ch2[1].first] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (Deg[i] == 0 && Dep[i] != mxdep) {
      for (int i = 1; i <= q; i++) puts("Fou");
      return 0;
    }
  Fa2[1] = 0;
  for (int i = 2; i <= n; i++)
    if (Fa1[i].second != -1) add(i, 1);
  for (int i = 1; i <= q; i++) {
    int a;
    char ch[7];
    scanf("%d%s", &a, ch);
    if (Fa1[a].second != -1) add(a, -1);
    if ((Fa1[a].second = chg(ch[0])) != -1) add(a, 1);
    getans();
  }
  return 0;
}
