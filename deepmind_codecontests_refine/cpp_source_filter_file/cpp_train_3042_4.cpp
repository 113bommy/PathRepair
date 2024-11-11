#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long INF = 1e18;
void solve() {
  string s;
  cin >> s;
  long long n = s.length();
  vector<vector<long long>> v(n + 1, vector<long long>(30, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (j == s[i] - 'a') {
        v[i + 1][j]++;
      }
      v[i + 1][j] += v[i][j];
    }
  }
  long long q;
  cin >> q;
  while (q--) {
    long long l, r;
    cin >> l >> r;
    if (r - l + 1 == 1) {
      cout << "Yes \n";
      continue;
    }
    long long e1 = s[l - 1] - 'a', e2 = s[r - 1] - 'a';
    if (e1 != e2)
      cout << "Yes \n";
    else {
      long long ct = 0;
      if (v[r][e1] - v[l - 1][e1] >= r - l) {
        cout << "No \n";
        continue;
      }
      for (int i = 0; i < 26; i++) {
        if (i != e1) {
          if (v[r][i] - v[l - 1][i] > 1) ct++;
        }
      }
      if (ct >= 2)
        cout << "Yes \n";
      else
        cout << "No \n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long no_of_test_cases = 1;
  while (no_of_test_cases--) {
    solve();
  }
  return 0;
}
