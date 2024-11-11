#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
std::vector<std::vector<int> > ch;
std::vector<int> vis;
std::vector<int> lev;
std::vector<int> home;
std::vector<int> st;
int curt = 0;
int tin[100000], tout[100000];
void dfs(int v) {
  st[v] = 1;
  tin[v] = curt++;
  for (auto u : ch[v]) {
    lev[u] = lev[v] + 1;
    home[u] = home[v];
    dfs(u);
    st[v] += st[u];
  }
  tout[v] = curt++;
}
int main() {
  int n, m, k, q;
  scanf("%d %d %d %d", &n, &m, &k, &q);
  std::vector<int> a(k), b(k);
  for (int i = 0; i < k; i++) scanf("%d %d", &a[i], &b[i]);
  std::vector<int> visa(n + 1, 0);
  std::vector<int> visb(m + 1, 0);
  std::vector<int> valid(k, 0);
  for (int i = k - 1; i >= 0; i--) {
    if (visa[a[i]] == 0) valid[i]++;
    visa[a[i]] = 1;
    visb[b[i]] = 1;
  }
  std::vector<int> last(m + 1, -1);
  ch.resize(n + 1);
  vis = std::vector<int>(n + 1, 0);
  std::vector<int> par(n + 1, 0);
  for (int i = 0; i < k; i++) {
    if (valid[i] && last[b[i]] != -1) {
      ch[last[b[i]]].push_back(a[i]);
      par[a[i]] = last[b[i]];
    }
    last[b[i]] = a[i];
  }
  lev = std::vector<int>(n + 1, 0);
  home = std::vector<int>(n + 1, 0);
  st.resize(n + 1);
  for (int i = 1; i < n + 1; i++) {
    if (par[i] == 0) {
      home[i] = i;
      dfs(i);
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (last[y] == -1) {
      printf("0\n");
      continue;
    }
    int to = last[y];
    if (home[to] != home[x])
      printf("0\n");
    else {
      if (tin[to] < tin[x] || tout[to] > tout[x])
        printf("0\n");
      else
        printf("%d\n", st[x]);
    }
  }
}
