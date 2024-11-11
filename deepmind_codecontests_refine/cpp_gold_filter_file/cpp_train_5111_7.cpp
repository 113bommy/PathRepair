#include <bits/stdc++.h>
using namespace std;
typedef const int& ci;
int ans[1000000 + 1];
int hsn[1000000 + 1], dp[1000000 + 1], *top = dp;
vector<int> sn[1000000 + 1];
int dfs(ci u, ci p) {
  vector<int>::iterator par, hsu;
  int hln = 0, sln;
  bool flag;
  for (vector<int>::iterator i = sn[u].begin(), ed = sn[u].end(); i != ed;
       ++i) {
    if (*i == p) {
      par = i;
      flag = 1;
      continue;
    }
    if ((sln = dfs(*i, u)) > hln) hln = sln, hsu = i, flag = 0;
  }
  if (hln) {
    hsn[u] = *hsu;
    if (flag) {
      sn[u].erase(par);
      sn[u].erase(hsu);
    } else {
      sn[u].erase(hsu);
      sn[u].erase(par);
    }
    sn[u].shrink_to_fit();
    return hln + 1;
  }
  hsn[u] = 0;
  sn[u].erase(par);
  sn[u].shrink_to_fit();
  return 1;
}
void dfs(ci u) {
  vector<int>::iterator hsu;
  int hln = 0, sln;
  for (vector<int>::iterator i = sn[u].begin(), ed = sn[u].end(); i != ed; ++i)
    if ((sln = dfs(*i, u)) > hln) hln = sln, hsu = i;
  hsn[u] = *hsu;
  sn[u].erase(hsu);
  sn[u].shrink_to_fit();
}
void solve(ci u);
int solve_ret(ci u) {
  int* dpu = ++top;
  *dpu = 1;
  int hsu = hsn[u];
  if (hsu) {
    int asu = solve_ret(hsu);
    int *dpe = top, num = asu ? dpu[++asu] : 1;
    for (vector<int>::iterator i = sn[u].begin(), ed = sn[u].end(); i != ed;
         ++i) {
      solve(*i);
      for (int j = top - dpe; j; --j)
        (dpu[j] += dpe[j]) >= num && (num = dpu[j], asu = j);
      top = dpe;
    }
    return ans[u] = asu;
  }
  return 0;
}
void solve(ci u) {
  int* dpu = ++top;
  *dpu = 1;
  int hsu = hsn[u];
  if (hsu) {
    int asu = solve_ret(hsu);
    int *dpe = top, num = asu ? dpu[++asu] : 1;
    for (vector<int>::iterator i = sn[u].begin(), ed = sn[u].end(); i != ed;
         ++i) {
      solve(*i);
      for (int j = top - dpe; j; --j)
        (dpu[j] += dpe[j]) >= num && (num = dpu[j], asu = j);
      top = dpe;
    }
    ans[u] = asu;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    puts("0");
    return 0;
  }
  for (int i = n, u, v; --i; sn[u].push_back(v), sn[v].push_back(u))
    scanf("%d%d", &u, &v);
  dfs(1);
  memset(ans, 0, sizeof(ans));
  solve(1);
  for (int i = 1; i <= n; ++i) printf("%d\n", ans[i]);
  return 0;
}
