#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, s8 = 0, sr, k;
  cin >> n;
  string s;
  cin >> s;
  for (i = 0; i < n; i++)
    if (s[i] == '8') s8 = s8 + 1;
  sr = n - s8;
  int a = sr / 10;
  if (s8 > a) {
    k = a;
    s8 = s8 - a;
    sr = sr - a * 10;
    if (sr + s8 - 1 >= 10) {
      s8 = s8 - 1 - (10 - sr);
      k = k + 1;
      int c = s8 / 11;
      k = k + c;
    }
  } else
    k = s8;
  cout << k;
}
