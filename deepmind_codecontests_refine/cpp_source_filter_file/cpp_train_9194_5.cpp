#include <bits/stdc++.h>
using namespace std;
int a[100][2501];
const int delta = 1000000007;
int main() {
  string s = "abcdefghijklmnopqrstuvwxyz";
  for (int i = 1; i <= 100; i++) {
    for (int j = 0; j <= 2500; j++) {
      if (j / i >= 26) {
        a[i][j] = 0;
      } else if (i == 1)
        a[i][j] = 1;
      else {
        for (int k = 0; k <= min(25, j); k++) {
          a[i - 1][j] = (a[i - 1][j] + a[i - 2][j - k]) % delta;
        }
      }
    }
  }
  int t, s1 = 0, n = 0;
  string s2;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> s2;
    s1 = 0;
    n = 0;
    for (char a : s2) {
      s1 += s.find(a);
      n++;
    }
    cout << a[n][s1] - 1 << endl;
  }
}
