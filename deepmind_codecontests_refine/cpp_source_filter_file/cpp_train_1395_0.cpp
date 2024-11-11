#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int i, j, k;
  cin >> str;
  int n = str.length();
  long long int res = 0;
  long long int d[n];
  d[0] = 1;
  for (i = 1; i < n; i++) {
    d[i] = d[i - 1] * 2;
    d[i] = d[i] % 1000000007;
    ;
  }
  for (int i = 0; i < n; i++) {
    if (str[i] = '1') {
      res = (res + d[n - 1 - i] * d[n - 1]) % 1000000007;
      ;
    }
  }
  res = res % 1000000007;
  ;
  cout << res << "\n";
}
