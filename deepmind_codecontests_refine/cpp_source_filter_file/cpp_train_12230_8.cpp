#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
const int N = 100 + 5;
int n, m;
char c[10];
bool possible = true;
vector<vector<int> > l(N);
vector<vector<int> > r(N);
int go[N][2];
int p[N];
int dfs(int v, int ma) {
  if (!possible) return -1;
  int q = 1;
  if (((int)((l[v]).size()))) {
    go[v][0] = v + 1;
    int sa = dfs(v + 1, l[v].back());
    if (sa == -1) return -1;
    q += sa;
  }
  if (((int)((r[v]).size()))) {
    if (r[v].front() < v + q) {
      possible = false;
      return -1;
    }
    ma = max(ma, r[v].back());
  }
  if (ma >= v + q) {
    go[v][1] = v + q;
    int sa = dfs(v + q, ma);
    if (sa == -1) return -1;
    q += sa;
  }
  return q;
}
void dfsprint(int v) {
  if (go[v][0] != -1) {
    dfsprint(go[v][0]);
  }
  printf("%d ", v + 1);
  if (go[v][1] != -1) {
    dfsprint(go[v][1]);
  }
}
void solve() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (int)(m); ++i) {
    int s, f;
    scanf("%d%d%s", &s, &f, &c);
    --s;
    --f;
    if (s > f) possible = false;
    if (c[0] == 'L')
      l[s].push_back(f);
    else
      r[s].push_back(f);
  }
  if (!possible) {
    puts("IMPOSSIBLE");
    return;
  }
  memset(go, -1, sizeof go);
  memset(p, -1, sizeof p);
  for (int i = 0; i < (int)(n); ++i) {
    sort((l[i]).begin(), (l[i]).end());
    sort((r[i]).begin(), (r[i]).end());
  }
  dfs(0, n - 1);
  if (!possible) {
    puts("IMPOSSIBLE");
    return;
  }
  dfsprint(0);
  puts("");
}
void testgen() {
  FILE* f = fopen("input.txt", "w");
  int T = 10;
  fclose(f);
}
int main() {
  cout << fixed;
  cout.precision(15);
  cerr << fixed;
  cerr.precision(12);
  solve();
  return 0;
}
