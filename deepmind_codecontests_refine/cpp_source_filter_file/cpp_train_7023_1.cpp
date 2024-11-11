#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  long long **a = new long long *[n];
  long long *b = new long long[n];
  long long *c = new long long[n];
  for (long long i = 0; i < n; ++i) {
    a[i] = new long long[m];
    b[i] = 0;
    c[i] = 0;
    string s;
    cin >> s;
    for (long long j = 0; j < m; ++j) {
      a[i][j] = (long long)s[j];
    }
  }
  long long j = 0;
  long long ans = 0;
  while (true) {
    bool removed = false;
    for (long long i = 0; i < n - 1; ++i) {
      c[i] = b[i];
    }
    if (j == m) {
      break;
    }
    for (long long i = 0; i < n - 1; ++i) {
      if (c[i] != 0) {
        continue;
      }
      if (a[i][j] > a[i + 1][j]) {
        c[i] = 1;
      } else if (a[i][j] == a[i + 1][j]) {
        c[i] = 0;
      } else if (a[i][j] < a[i + 1][j]) {
        removed = true;
        ++ans;
        break;
      }
    }
    if (!removed) {
      for (long long i = 0; i < n - 1; ++i) {
        b[i] = c[i];
      }
    }
    ++j;
  }
  cout << ans;
  return 0;
}
