#include <bits/stdc++.h>
using namespace std;
vector<int> v[507];
int t[507][507];
int r[507];
int main() {
  int n, m, z, sz, c = 0;
  scanf("%d", &n);
  ;
  scanf("%d", &m);
  ;
  scanf("%d", &z);
  ;
  string s;
  for (int i = 0; i <= 500; ++i)
    for (int j = 0; j <= 500; ++j) t[i][j] = 25000;
  t[0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> s;
    for (int j = 0; j < m; ++j) {
      if (s[j] == '1') v[i].push_back(j + 1);
    }
    for (int j = 0; j <= 500; ++j) r[j] = 25000;
    sz = v[i].size();
    c += sz;
    r[sz] = 0;
    r[sz - 1] = 1;
    for (int j = sz - 2; j >= 0; --j) {
      for (int k = 0; k <= j; ++k) {
        r[j] = min(r[j], v[i][sz - j + k - 1] - v[i][k] + 1);
      }
    }
    for (int j = 0; j <= 500; ++j) {
      for (int k = 0; k <= min(j, sz); ++k) {
        t[i][j] = min(t[i][j], t[i - 1][j - k] + r[k]);
      }
    }
  }
  if (z > c)
    cout << 0;
  else
    cout << t[n][z];
  return 0;
}
