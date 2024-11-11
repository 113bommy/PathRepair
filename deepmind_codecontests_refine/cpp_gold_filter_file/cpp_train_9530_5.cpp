#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  long long t, n, i, j, k, f;
  cin >> n;
  f = 0;
  for (i = 0; i < n; i++) {
    cin >> s >> j >> k;
    if (j >= 2400 && k - j > 0) {
      f = 1;
    }
  }
  if (f == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
