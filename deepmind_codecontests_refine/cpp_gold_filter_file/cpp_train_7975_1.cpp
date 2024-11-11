#include <bits/stdc++.h>
using namespace std;
int pd[110][2010];
int n;
int t[110], d[110], p[110], id[110];
int solve(int pos, int lul) {
  if (pos == n) return pd[pos][lul] = 0;
  int& ret = pd[pos][lul];
  if (ret != -1) return ret;
  ret = solve(pos + 1, lul);
  if (lul + t[pos] < d[pos])
    ret = max(solve(pos + 1, lul), p[pos] + solve(pos + 1, lul + t[pos]));
  return ret;
}
vector<int> ans;
void trace(int pos, int lul) {
  if (pos == n) return;
  if (pd[pos][lul] == pd[pos + 1][lul])
    trace(pos + 1, lul);
  else {
    ans.push_back(id[pos]);
    trace(pos + 1, lul + t[pos]);
  }
}
int main() {
  scanf("%d", &n);
  vector<tuple<int, int, int, int> > v;
  for (int i = 0; i < n; i++) {
    int tc, dc, pc;
    scanf("%d %d %d", &tc, &dc, &pc);
    v.emplace_back(dc, tc, pc, i + 1);
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) tie(d[i], t[i], p[i], id[i]) = v[i];
  memset(pd, -1, sizeof(pd));
  printf("%d\n", solve(0, 0));
  trace(0, 0);
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d%c", ans[i], " \n"[i == ans.size() - 1]);
  return 0;
}
