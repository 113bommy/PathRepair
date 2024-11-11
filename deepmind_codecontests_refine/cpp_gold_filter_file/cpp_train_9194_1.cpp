#include <bits/stdc++.h>
using namespace std;
long long comb[4000][200], mod = 1000000007, comb2[4000][4000];
int main() {
  int i, j;
  for (i = 0; i < 4000; i++) {
    for (j = 0; j < 200; j++) {
      if (i < j) {
        comb[i][j] = 0;
        continue;
      }
      if (j == 0 || j == i) {
        comb[i][j] = 1;
        continue;
      }
      comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % mod;
    }
  }
  for (i = 0; i < 4000; i++) {
    for (j = 0; j < 4000; j++) {
      if (i < j) {
        comb2[i][j] = 0;
        continue;
      }
      if (j == 0 || j == i) {
        comb2[i][j] = 1;
        continue;
      }
      comb2[i][j] = (comb2[i - 1][j] + comb2[i - 1][j - 1]) % mod;
    }
  }
  cin >> i;
  string str;
  while (i--) {
    cin >> str;
    j = 0;
    for (int k = 0; k < str.length(); k++) {
      j += str[k] - 'a';
    }
    long long aa = j + str.length() - 1, bb = str.length() - 1;
    long long sgn = 1;
    long long res = 0;
    for (j = 0; j < str.length(); j++) {
      int aaaa = aa - j * 26;
      if (aaaa >= 0) {
        res += sgn * (comb[aaaa][bb] * comb2[str.size()][j]);
        res %= mod;
      }
      sgn *= -1;
    }
    res -= 1;
    while (res < 0) {
      res += mod;
    }
    cout << res << endl;
  }
}
