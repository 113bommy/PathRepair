#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long int N = 2e5 + 100;
long long int t[N][26];
int32_t main() {
  string s;
  cin >> s;
  long long int n = s.size();
  for (long long int i = 1; i <= n; i++) {
    long long int z = (s[i - 1] - 'a');
    for (long long int j = 0; j < 26; j++) {
      t[i][j] = t[i - 1][j];
      if (j == z) t[i][j]++;
    }
  }
  long long int q;
  cin >> q;
  for (long long int i = 0; i < q; i++) {
    long long int l, r;
    cin >> l >> r;
    if (s[l - 1] != s[r - 1]) {
      cout << "Yes" << '\n';
      continue;
    }
    long long int z = (s[l - 1] - 'a');
    long long int p1 = 0;
    for (long long int j = 0; j < 26; j++) {
      if (t[r][j] - t[l - 1][j] > 0) p1++;
    }
    if (p1 < 2 && r != l) {
      cout << "No" << '\n';
    } else {
      cout << "Yes" << '\n';
    }
  }
}
