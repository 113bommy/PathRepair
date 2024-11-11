#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 1067;
vector<int> vao[N], ra[N];
int it[N * 4], trai[N * 4], phai[N * 4];
long long w[N];
int s[N], t[N], d[N];
long long f[N][201];
void build(int x, int l, int r) {
  trai[x] = l;
  phai[x] = r;
  if (l == r) {
    it[x] = 0;
    return;
  }
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
}
int mi(int c1, int c2) {
  if (w[c1] > w[c2] || (w[c1] == w[c2] && d[c1] > d[c2]))
    return c1;
  else
    return c2;
}
void update(int x, int l, int c) {
  if (trai[x] > l || phai[x] < l) return;
  if (trai[x] == phai[x]) {
    it[x] = c;
    return;
  }
  update(x * 2, l, c);
  update(x * 2 + 1, l, c);
  it[x] = mi(it[x * 2], it[x * 2 + 1]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    cin >> s[i] >> t[i] >> d[i] >> w[i];
    t[i]++;
    vao[s[i]].push_back(i);
    ra[t[i]].push_back(i);
    d[i]++;
  }
  build(1, 1, n);
  for (int i = 1; i <= n + 1; i++)
    for (int j = 0; j <= m; j++) f[i][j] = 1e15;
  f[1][m] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= (int)vao[i].size() - 1; j++) {
      update(1, vao[i][j], vao[i][j]);
    }
    for (int j = 0; j <= (int)ra[i].size() - 1; j++) {
      update(1, ra[i][j], 0);
    }
    for (int j = 1; j <= m; j++) {
      f[i + 1][j - 1] = min(f[i + 1][j - 1], f[i][j]);
    }
    int t = it[1];
    for (int j = 0; j <= m; j++) {
      if (t != 0)
        f[d[t]][j] = min(f[d[t]][j], f[i][j] + w[t]);
      else
        f[i + 1][j] = min(f[i + 1][j], f[i][j]);
    }
  }
  long long res = 1e15;
  for (int i = 0; i <= m; i++) res = min(res, f[n + 1][i]);
  cout << res << endl;
  return 0;
}
