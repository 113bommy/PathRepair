#include <bits/stdc++.h>
using namespace std;
const int N = 30005, M = 550005;
using ll = long long;
int w, n, m, pw[15], a[N];
ll cc[N], cnt[M];
char s[15];
int calc(int num) {
  int ret = 0;
  for (int i = 0; i < w; i++)
    if (num & (1 << i)) ret += pw[i];
  return ret;
}
ll dfs(int dep, int cur) {
  if (dep == w + 1) return cnt[cur];
  int t = pw[w - dep];
  if (s[dep] == 'A') return dfs(dep + 1, cur) + dfs(dep + 1, cur + t);
  if (s[dep] == 'O') return dfs(dep + 1, cur);
  if (s[dep] == 'X') return dfs(dep + 1, cur) + dfs(dep + 1, cur + t * 2);
  if (s[dep] == 'a') return dfs(dep + 1, cur + t * 2);
  if (s[dep] == 'o') return dfs(dep + 1, cur + t) + dfs(dep + 1, cur + t * 2);
  return dfs(dep + 1, cur + t);
}
int main() {
  ios::sync_with_stdio(false);
  cin >> w >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i], ++cc[a[i]];
  pw[0] = 1;
  for (int i = 1; i <= 12; i++) pw[i] = pw[i - 1] * 3;
  for (int i = 0; i < (1 << w); i++)
    for (int j = 0; j < (1 << w); j++) cnt[calc(i) + calc(j)] += cc[i] * cc[j];
  while (m--) {
    cin >> (s + 1);
    cout << dfs(1, 0) << endl;
  }
  return 0;
}
