#include <bits/stdc++.h>
using namespace std;
long long int hell = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  t = 1;
  while (t--) {
    long long int n;
    cin >> n;
    map<string, long long int> m, M;
    string mm;
    long long int mx = -1 * hell;
    string s[n];
    long long int x[n];
    for (long long int i = 0; i < n; i++) {
      cin >> s[i] >> x[i];
      m[s[i]] = m[s[i]] + x[i];
    }
    for (long long int i = 0; i < n; i++) mx = max(mx, m[s[i]]);
    long long int i = 0;
    while (m[s[i]] != mx || M[s[i]] + x[i] != mx) {
      M[s[i]] += x[i];
      i++;
    }
    cout << s[i];
  }
  return 0;
}
