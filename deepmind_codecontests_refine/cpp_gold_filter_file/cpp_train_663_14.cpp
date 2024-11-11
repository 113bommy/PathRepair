#include <bits/stdc++.h>
using namespace std;
char str[51234];
int L[51234][123];
int P[51234][27];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> str;
  n = strlen(str);
  memset(P, 0x3f, sizeof(P));
  for (int i = n - 1; i >= 0; --i) {
    P[i][str[i] - 'a'] = i;
    for (int j = 0; j < 26; ++j) {
      P[i][j] = min(P[i + 1][j], P[i][j]);
    }
  }
  memset(L, 0x3f, sizeof(L));
  for (int i = 0; i < n; ++i) {
    L[i][0] = i - 1;
    L[i][1] = i;
  }
  for (int k = 2; k < 102; ++k) {
    for (int i = n - 1; i >= 0; --i) {
      if (i + k <= n) {
        int t = L[i + 1][k - 2] + 1;
        if (t < n) {
          L[i][k] = min(L[i + 1][k], P[t][str[i] - 'a']);
        } else {
          L[i][k] = L[i + 1][k];
        }
      }
    }
  }
  int l, r;
  bool flag = 0;
  for (int i = 0; i < n; ++i) {
    for (int k = 100; k >= 1; --k) {
      if (L[i][k] < n) {
        l = i, r = L[i][k];
        n = k;
        flag = 1;
      }
      if (flag) break;
    }
    if (flag) break;
  }
  string s1;
  for (int i = l; i <= r; ++i) {
    s1 += str[i];
  }
  string prefix, surfix;
  for (int i = 0; i < s1.length(); ++i) {
    if (L[i + 1 + l][n] < l + s1.length()) {
      s1 = s1.substr(0, L[i + 1 + l][n] - l + 1);
      continue;
    } else if (L[i + l][n] == l + s1.length() - 1) {
      prefix = prefix + s1[i];
      n--;
      if (i != s1.length() - 1) surfix = s1[s1.length() - 1] + surfix, n--;
      s1 = s1.substr(0, s1.length() - 1);
    } else {
      s1 = s1.substr(0, s1.length() - 1);
      i--;
    }
    if (n <= 0) break;
  }
  cout << prefix << surfix << endl;
  return 0;
}
