#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7;
const char c = 12;
int maxi = -1;
int z[3][2000002];
int len;
int maxz1, maxz2;
string t, p, s;
void Z_functions(int type, string s) {
  int l = -1;
  int r = -1;
  for (int i = 1; i <= (s.size() - 1); i++) {
    if (i > r) {
      l = r = i;
      while (r < s.size() && s[r - l] == s[r]) {
        r++;
      }
      z[type][i] = r - l;
      r--;
    } else {
      if (z[type][i - l] < r - i + 1) {
        z[type][i] = z[type][i - l];
      } else {
        l = i;
        while (r < s.size() && s[r - l] == s[r]) {
          r++;
        }
        z[type][i] = r - l;
        r--;
      }
    }
  }
  return;
}
int main() {
  getline(cin, t);
  getline(cin, p);
  while (t.size() < p.size()) {
    t = t + c;
  }
  while (t.size() > p.size()) {
    p = p + c;
  }
  len = t.size();
  reverse(t.begin(), t.end());
  s = t;
  reverse(t.begin(), t.end());
  Z_functions(1, p + c + t);
  Z_functions(2, s + c + p);
  for (int i = 0; i < (len + 1); i++) {
    maxz1 = max(maxz1, z[1][i + len]);
    maxz2 = max(maxz2, z[2][i + len]);
  }
  while (maxi + 1 < len && t[++maxi] == p[len - maxi - 1])
    ;
  maxi--;
  for (int i = maxi; i >= 0; i--) {
    int zz = z[1][len + i + 2];
    if (i + zz + maxz2 + 1 < len) {
      continue;
    }
    for (int j = i + 1; j <= i + zz + 1; j++) {
      int zzz = z[2][len + j - i];
      if (j + zzz >= len) {
        cout << i << ' ' << j;
        return 0;
      }
    }
  }
  cout << -1 << ' ' << -1;
  return 0;
}
