#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long int n;
  cin >> n;
  cin >> s;
  long long int d = 0;
  for (long long int i = n / 2; i >= 2; i--) {
    if (s[i] == s[0]) {
      int k = 0;
      for (long long int j = 1; j < i; j++) {
        if (s[j] != s[i] + j) {
          k = 1;
          break;
        }
      }
      if (k == 0) {
        d = i;
        break;
      }
    }
  }
  if (d == 0)
    cout << n;
  else
    cout << n - (d - 1);
}
