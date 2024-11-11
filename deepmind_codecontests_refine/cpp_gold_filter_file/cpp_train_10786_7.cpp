#include <bits/stdc++.h>
using namespace std;
const int N = 1000000 + 1067, base = 1000000007;
long long f[N][3], sum[N][3][3];
int u[N], v[N], link[N], head[N], con[N];
string s, t;
void dfs(int x, int t) {
  int h = head[x];
  sum[x][0][0] = sum[x][1][1] = sum[x][0][1] = sum[x][1][0] = 1;
  while (h) {
    if (v[h] != t) {
      dfs(v[h], x);
      f[x][0] = (f[x][0] * (sum[v[h]][0][1] + sum[v[h]][0][0]) % base +
                 f[v[h]][1] * sum[x][1][1] % base + f[v[h]][0] * sum[x][0][0]) %
                base;
      f[x][1] = (f[x][1] * (sum[v[h]][1][1] + sum[v[h]][1][0]) % base +
                 f[v[h]][1] * sum[x][1][0] % base + f[v[h]][0] * sum[x][0][1]) %
                base;
      sum[x][1][1] = sum[x][1][1] * (sum[v[h]][0][1] + sum[v[h]][0][0]) % base;
      sum[x][1][0] = sum[x][1][0] * (sum[v[h]][1][1] + sum[v[h]][1][0]) % base;
      sum[x][0][1] = sum[x][0][1] * (sum[v[h]][1][1] + sum[v[h]][1][0]) % base;
      sum[x][0][0] = sum[x][0][0] * (sum[v[h]][0][1] + sum[v[h]][0][0]) % base;
      ++con[x];
    }
    h = link[h];
  }
  if (con[x] == 0) sum[x][0][1] = sum[x][1][0] = 0;
  f[x][0] = (f[x][0] + sum[x][0][0]) % base;
  f[x][1] = (f[x][1] + sum[x][0][1]) % base;
  if (con[x] == 0) f[x][1] = (f[x][1] + sum[x][1][1]) % base;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int m = n - 1;
  for (int i = 1; i <= m; i++) {
    cin >> u[i] >> v[i];
    link[i] = head[u[i]];
    head[u[i]] = i;
    link[i + m] = head[v[i]];
    head[v[i]] = i + m;
    v[i + m] = u[i];
  }
  dfs(1, 0);
  if (con[1] == 1)
    cout << (f[1][0] + sum[1][0][1]) % base << endl;
  else
    cout << (f[1][1] + f[1][0]) % base << endl;
  return 0;
}
