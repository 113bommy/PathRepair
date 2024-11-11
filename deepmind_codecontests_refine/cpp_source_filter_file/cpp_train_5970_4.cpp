#include <bits/stdc++.h>
using namespace std;
string s[2000 + 5];
int a[2000 + 5];
map<pair<pair<int, int>, int>, int> f;
map<pair<pair<int, int>, int>, bool> g;
int val(int id1, int id2) {
  for (int i = 0; i < min(s[id1].length(), s[id2].length()); i++)
    if (s[id1][i] != s[id2][i]) return i;
  return min(s[id1].length(), s[id2].length());
}
int dfs(int l, int r, int k) {
  if (k == 0) return 0;
  if (l == r) {
    if (k <= 1) return 0;
    return -1e9;
  }
  if (g[make_pair(make_pair(l, r), k)]) return f[make_pair(make_pair(l, r), k)];
  g[make_pair(make_pair(l, r), k)] = true;
  int id = l;
  for (int i = l + 1; i < r; i++)
    if (a[i] < a[id]) id = i;
  int ans = 0;
  for (int i = 0; i <= k; i++)
    ans = max(ans, dfs(l, id, i) + dfs(id + 1, r, k - i) + a[id] * i * (k - i));
  return f[make_pair(make_pair(l, r), k)] = ans;
}
int main() {
  int n, k, r, i;
  scanf("%d%d", &n, &k);
  for (i = 1; i <= n; i++) cin >> s[i];
  sort(s + 1, s + n + 1);
  for (i = 1; i < n; i++) a[i] = val(i, i + 1);
  printf("%d\n", dfs(1, n, k));
}
