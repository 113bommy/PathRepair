#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 7;
const int maxm = 6e6 + 7;
const long long mod = 1e9 + 7;
int n;
int fat[maxn];
int vis[maxn];
long long a[maxn];
int ans[maxn];
int father(int x) {
  if (fat[x] != x)
    return (fat[x] = father(fat[x]));
  else
    return x;
}
void unionn(int x, int y) { fat[father(y)] = father(x); }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> n;
  for (int i = (1); i <= (n); ++i) cin >> a[i], fat[i] = i;
  for (int i = (1); i <= (n); ++i) {
    for (int j = (i + 1); j <= (n); ++j) {
      long long tmp = a[i] * a[j];
      if (tmp <= 0) continue;
      long long tp = sqrt(tmp);
      if (tp * tp == tmp) unionn(i, j);
    }
  }
  for (int i = (1); i <= (n); ++i) {
    memset(vis, 0, sizeof(vis));
    int nw = 0;
    for (int j = (i); j <= (n); ++j) {
      if (a[j]) {
        int f = father(j);
        if (!vis[f]) nw++, vis[f]++;
      }
      ans[max(nw, 1)]++;
    }
  }
  for (int i = (1); i <= (n); ++i) cout << ans[i] << " ";
}
