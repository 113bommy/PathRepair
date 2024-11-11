#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, i = 0, l = -2, k = INT_MAX, j, a = 0, f = 0, c = 0, b = 0,
                   x = 100000000007, d, y, m, zero = 0, one = 0, z;
  string s = "qwertyuiopasdfghjkl;zxcvbnm,./", mar = "acb", maria;
  char cha;
  vector<long long int> vc, vct, vctt;
  vector<string> ch;
  vector<pair<int, int>> pa;
  map<long long int, int> mp;
  double num, nr, radi;
  stack<char> bra, bra2;
  cin >> n;
  k = n / 2 + 1;
  for (i = 1; i <= (n / 2 + 1); i++) {
    for (j = 1; j <= k; j++) {
      if (j + i > k)
        cout << "D";
      else
        cout << "*";
    }
    for (j = k + 1; j <= n; j++) {
      if (j - k < i)
        cout << "D";
      else
        cout << "*";
    }
    cout << endl;
  }
  c = k + 1;
  f = n / 2 - 1;
  for (i = 1; i < k; i++) {
    for (j = 1; j <= k; j++) {
      if (j > i)
        cout << "D";
      else
        cout << "*";
    }
    for (j = c; j <= n; j++) {
      if (j - c < f) {
        cout << "D";
      } else
        cout << "*";
    }
    f--;
    cout << endl;
  }
}
