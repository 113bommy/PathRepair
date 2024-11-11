#include <bits/stdc++.h>
using namespace std;
const long long mod1 = 998244353;
const long long mod2 = 1000000007;
int n, a[200005], c[200005], cnt;
vector<int> g[200005];
vector<int> fc[200005];
vector<int> v;
void dfs(int i) {
  if (c[i] != 0) return;
  c[i] = cnt;
  fc[cnt].push_back(i);
  for (int j = 0; j < (g[i].size()); j++) dfs(g[i][j]);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    g[i].push_back(a[i]);
    g[a[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (c[i] != 0) continue;
    cnt++;
    dfs(i);
    int p = fc[cnt][0];
    for (int j = 0; j < (fc[cnt].size()); j++) p = a[p];
    v.push_back(p);
  }
  int s = -1;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) {
      cnt--;
      s = i;
      break;
    }
  }
  if (s == -1) {
    s = v[0];
    a[s] = s;
  }
  for (int i = 0; i < (v.size()); i++)
    if (v[i] != s) a[v[i]] = s;
  cout << cnt << endl;
  for (int i = 1; i <= n; i++) {
    cout << a[i];
    cout << ((i == n) ? '\n' : ' ');
  }
  return 0;
}
