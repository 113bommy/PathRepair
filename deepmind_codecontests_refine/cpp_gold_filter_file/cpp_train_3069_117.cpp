#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long int power(long long int x, long long int y) {
  int res = 1, r = x;
  while (y > 0) {
    if (y & 1) res = res * r;
    r *= r;
    y = y >> 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    string s[8];
    int a = 0, b = 0, i, j;
    for (i = 0; i < 8; i++) cin >> s[i];
    for (i = 0; i < 8; i++) {
      for (j = 0; j < 8; j++) {
        if (s[i][j] == '.') continue;
        if (isupper(s[i][j])) {
          if (s[i][j] == 'Q')
            a += 9;
          else if (s[i][j] == 'R')
            a += 5;
          else if (s[i][j] == 'B')
            a += 3;
          else if (s[i][j] == 'N')
            a += 3;
          else if (s[i][j] == 'P')
            a += 1;
        } else {
          if (s[i][j] == 'q')
            b += 9;
          else if (s[i][j] == 'r')
            b += 5;
          else if (s[i][j] == 'b')
            b += 3;
          else if (s[i][j] == 'n')
            b += 3;
          else if (s[i][j] == 'p')
            b += 1;
        }
      }
    }
    if (a == b)
      cout << "Draw";
    else if (a > b)
      cout << "White";
    else
      cout << "Black";
  }
  return 0;
}
