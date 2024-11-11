#include <bits/stdc++.h>
using namespace std;
const int md = 1000000007;
const int maxn = 1010101;
const int maxn4 = 4 * maxn;
const long long inf = 2020202020202020202LL;
string s;
int n, m;
int pow2[30], oneit[maxn], fin[maxn], it[20][maxn];
int wr(int v, int pl) {
  int u = v, cpl = pl, l = 0, d = v;
  while (u != 0) {
    if (u % 2) {
      cpl = it[l][cpl - d + 1] + d - pow2[l];
      d = d - pow2[l];
    }
    u /= 2;
    l++;
  }
  return cpl;
}
void do_it(int k, int d) {
  int l = 0;
  for (int i = 0; i < n; i++) it[0][i] = i;
  for (int i = 0; i < d; i++)
    for (int j = 0; j <= n / d, i + d * j < k; ++j) {
      it[0][l] = i + d * j;
      l++;
    }
  for (int i = 1; i < 20; i++)
    for (int j = 0; j < n; j++) it[i][j] = it[i - 1][it[i - 1][j] + 1];
  fin[0] = 0;
  for (int i = 0; i <= n - k; i++) fin[i] = wr(i + 1, i);
  for (int i = n - k + 1; i < n; i++) fin[i] = wr(n - k + 1, i);
  string s2;
  s2.resize(n);
  for (int i = 0; i < n; i++) s2[i] = s[fin[i]];
  s = s2;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  cin >> m;
  pow2[0] = 1;
  for (int i = 0; i < 21; i++) pow2[i + 1] = pow2[i] * 2;
  n = s.length();
  for (int i = 0; i < m; i++) {
    int k, d;
    cin >> k >> d;
    do_it(k, d);
    cout << s;
    cout << '/n';
  }
  return 0;
}
