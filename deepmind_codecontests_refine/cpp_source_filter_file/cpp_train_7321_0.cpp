#include <bits/stdc++.h>
using namespace std;
class Shoe {
 public:
  int c, s, k;
  void init() { cin >> c >> s; }
} shoe[100010];
int N, M, mtch[100010];
bool vst[100010], wtf[100010];
vector<int> adj[100010];
bool cmp(Shoe a, Shoe b) { return a.s < b.s; }
bool cmp2(Shoe a, Shoe b) { return a.c > b.c; }
int dfs(int u) {
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (vst[v] == 0 && wtf[v] == 0) {
      vst[v] = 1;
      if (mtch[v] == 0 || dfs(mtch[v])) {
        if (mtch[v]) wtf[v] = true;
        mtch[v] = u;
        return true;
      }
    }
  }
  return false;
}
int main() {
  cin >> N;
  for (int i = 1; i <= N; i++) shoe[i].init(), shoe[i].k = i;
  sort(shoe + 1, shoe + N + 1, cmp);
  cin >> M;
  for (int i = 1; i <= M; i++) {
    int a, b, l = 1, r = N, m, x = -1;
    cin >> a >> b;
    while (l < r) {
      m = (l + r) >> 1;
      if (shoe[m].s < b)
        l = m + 1;
      else if (shoe[m].s > b)
        r = m - 1;
      else {
        x = m;
        break;
      }
    }
    if (m != x) m = l;
    if (shoe[m].s == b || shoe[m].s == b + 1)
      if (shoe[m].c <= a) adj[shoe[m].k].push_back(i);
    ++m;
    if (shoe[m].s == b || shoe[m].s == b + 1)
      if (shoe[m].c <= a) adj[shoe[m].k].push_back(i);
  }
  sort(shoe + 1, shoe + N + 1, cmp2);
  long long ans = 0, cnt = 0;
  for (int i = 1; i <= N; i++) {
    memset(vst, 0, sizeof(vst));
    if (dfs(shoe[i].k)) ans += shoe[i].c, cnt++;
  }
  cout << ans << endl << cnt << endl;
  for (int i = 1; i <= M; i++)
    if (mtch[i]) cout << i << " " << mtch[i] << endl;
  return 0;
}
