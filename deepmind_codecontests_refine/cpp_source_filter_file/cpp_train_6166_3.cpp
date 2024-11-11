#include <bits/stdc++.h>
using namespace std;
long long t, n, m, k, d, e, q, b, c, bo, r, l, h, i, j, mm, kk, jj, w, x, y, g,
    a, mod = 1e9 + 7, z, ax, bx, ay, by, xx, yy;
vector<long long> v, vv;
pair<long long, long long> p[1000001];
map<long long, long long> mp, mpp, vis, mpx, mpy;
set<long long> se;
string s[1000001], second, sss;
char cc;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> s[i];
    b = 1;
    for (j = 1; j < m; j++) {
      if (s[i][j] != s[i][j - 1]) b = 0;
    }
    mp[i] = b;
    a = max(b, a);
  }
  for (i = 0; i < n; i++) {
    if (mpp[i] == 0) {
      for (j = i + 1; j < n; j++) {
        if (mpp[j] == 0) {
          b = 0;
          for (k = 0; k < m; k++) {
            if (s[i][k] != s[j][m - k - 1]) b = 1;
          }
          if (b == 0) {
            second += s[i];
            sss = s[j] + sss;
            mpp[i] = 1;
            mpp[j] = 1;
            break;
          }
        }
      }
    }
  }
  for (i = 0; i < n; i++) {
    if (mp[i] == 1 && mpp[i] == 0) {
      second += s[i];
      break;
    }
  }
  z = second.size() + sss.size();
  cout << z << endl;
  cout << second << sss;
  return 0;
}
