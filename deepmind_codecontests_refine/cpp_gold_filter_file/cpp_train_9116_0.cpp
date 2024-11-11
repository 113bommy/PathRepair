#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
int n, m, p[maxn], f[maxn][1010][2], vote[1010][2];
string s1, s2, s3, s4, s5, na[maxn], val[maxn];
map<string, int> mp;
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> s1 >> s2 >> s3;
    na[i] = s1;
    mp[s1] = i;
    if (s3[0] != '0' && s3[0] != '1') {
      cin >> s4 >> s5;
      if (s5 == "?") swap(s3, s5);
      int p1 = mp[s3], p2 = mp[s5];
      if (s4 == "AND") {
        p[i] = 1;
        if (s3 == "?" && s5 == "?") {
          for (int j = 1; j <= m; ++j) f[i][j][0] = 0, f[i][j][1] = 1;
          continue;
        }
        if (s3 == "?") {
          for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p2][j][k] & k;
          continue;
        }
        for (int j = 1; j <= m; ++j)
          for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p1][j][k] & f[p2][j][k];
      }
      if (s4 == "OR") {
        p[i] = 2;
        if (s3 == "?" && s5 == "?") {
          for (int j = 1; j <= m; ++j) f[i][j][0] = 0, f[i][j][1] = 1;
          continue;
        }
        if (s3 == "?") {
          for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p2][j][k] | k;
          continue;
        }
        for (int j = 1; j <= m; ++j)
          for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p1][j][k] | f[p2][j][k];
      }
      if (s4 == "XOR") {
        p[i] = 3;
        if (s3 == "?" && s5 == "?") continue;
        if (s3 == "?") {
          for (int j = 1; j <= m; ++j)
            for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p2][j][k] ^ k;
          continue;
        }
        for (int j = 1; j <= m; ++j)
          for (int k = 0; k <= 1; ++k) f[i][j][k] = f[p1][j][k] ^ f[p2][j][k];
      }
    } else {
      for (int j = 1; j <= m; ++j) {
        f[i][j][0] = f[i][j][1] = s3[j - 1] - '0';
      }
    }
  }
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      for (int k = 0; k <= 1; ++k) {
        if (f[i][j][k] == 1) ++vote[j][k];
      }
  for (int i = 1; i <= m; ++i) {
    if (vote[i][0] <= vote[i][1])
      cout << 0;
    else
      cout << 1;
  }
  cout << "\n";
  for (int i = 1; i <= m; ++i) {
    if (vote[i][0] >= vote[i][1])
      cout << 0;
    else
      cout << 1;
  }
  return 0;
}
