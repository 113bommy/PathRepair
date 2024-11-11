#include <bits/stdc++.h>
using namespace std;
const int N = 2000001;
const int INF = 100000000;
void solve() {
  string s, d;
  cin >> s;
  int n;
  cin >> n;
  vector<int> a(26, 0), b(26);
  for (long long int i = 0; i < (s.size()); i++) {
    a[s[i] - 'a']++;
  }
  long long int k = 0, sum = 0;
  k = *max_element(a.begin(), a.end());
  for (long long int i = 1; i < (k + 1); i++) {
    for (long long int j = 0; j < (a.size()); j++) {
      sum += ceil(a[j] * 1.0 / i);
      b[j] = ceil(a[j] * 1.0 / i);
    }
    if (sum <= n) {
      for (long long int j = 0; j < (b.size()); j++) {
        for (long long int k = 0; k < (b[j]); k++) d.push_back((j + 'a'));
      }
      if (n > d.size()) {
        while (n != d.size()) {
          d.push_back(('a'));
        }
      }
      cout << i << '\n';
      cout << d;
      return;
    }
    sum = 0;
  }
  cout << -1;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T = 1;
  while (T--) {
    solve();
    cout << '\n';
  }
  return 0;
}
