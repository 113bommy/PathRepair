#include <bits/stdc++.h>
using namespace std;
int main() {
  long int n, t = 0;
  cin >> n;
  string s;
  cin >> s;
  long int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    if (s[t] == '>') {
      t = t + a[i];
      if (t >= n) {
        cout << "FINITE";
        return 0;
      }
    } else {
      t = t - a[i];
      if (t < 0) {
        cout << "FINITE";
        return 0;
      }
    }
  }
  cout << "INFINITE";
  return 0;
}
