#include <bits/stdc++.h>
using namespace std;
const int N = 35, M = 100005;
int n, m, f, ans, e;
char a[N][M];
int len[N], z[M], b[N][M], p[N][M];
vector<int> v[M];
void dfs(int pos) {
  if (f) return;
  z[pos] = 2;
  for (auto &i : v[pos])
    if (!z[i])
      dfs(i);
    else if (z[i] == 2) {
      f = 1;
      return;
    }
  z[pos] = 1;
}
bool check(int s, int t) {
  f = e = 0;
  z[0] = 0;
  v[0].clear();
  for (int i = b[s][1]; i <= b[t][len[t]]; i++) v[i].clear(), z[i] = 0;
  for (int i = s; i <= t; i++) {
    v[0].push_back(b[i][1]);
    for (int j = s; j <= t; j++) {
      int l = 0;
      for (int k = 1; k <= len[i]; k++) {
        while (k + l <= len[i] && l + 1 <= len[j] && a[i][k + l] == a[j][l + 1])
          ++l;
        if (l) {
          if (len[i] - k + 1 < len[j] && l == len[i] - k + 1)
            v[b[i][k]].push_back(b[j][l + 1]);
          if (len[j] < len[i] - k + 1 && l == len[j])
            v[b[i][k]].push_back(b[i][k + l]);
          if (k > 1 && len[i] - k + 1 == len[j] && l == len[j])
            v[b[i][k]].push_back(0);
          l = p[j][l];
        }
      }
    }
  }
  if (!z[0]) dfs(0);
  if (f) return 0;
  for (int i = b[s][1]; i <= b[t][len[t]]; i++)
    if (!z[i]) {
      dfs(i);
      if (f) return 0;
    }
  return 1;
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> (a[i] + 1);
    len[i] = strlen(a[i] + 1);
    for (int j = 1; j <= len[i]; j++) b[i][j] = ++m;
  }
  for (int i = 1; i <= n; i++) {
    int k = 0;
    for (int j = 2; j <= len[i]; j++) {
      while (k && a[i][k + 1] != a[i][j]) k = p[i][k];
      if (a[i][k + 1] == a[i][j]) ++k;
      p[i][j] = k;
    }
  }
  int j = 1;
  for (int i = 1; i <= n; i++) {
    if (i > j) j = i;
    while (j <= n && check(i, j)) ++j;
    ans += j - i;
  }
  cout << ans << endl;
  return 0;
}
