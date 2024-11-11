#include <bits/stdc++.h>
using namespace std;
vector<long long int> prefix_function(string s) {
  long long int n = s.size();
  vector<long long int> pi(n);
  pi[0] = 0;
  for (long long int i = 1; i < n; i++) {
    long long int j = pi[i - 1];
    while (j > 0 and s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void solve() {
  string s;
  cin >> s;
  long long int n = s.size();
  vector<long long int> pi(n);
  pi = prefix_function(s);
  long long int k = pi[n - 1];
  if (k == 0) {
    cout << "Just a legend\n";
    return;
  }
  for (long long int i = 1; i < n - 1; i++) {
    if (pi[i] == k) {
      string ans = s.substr(0, k);
      cout << ans << endl;
      return;
    }
  }
  k = pi[k];
  if (pi[k] == 0) {
    cout << "Just a legend\n";
    return;
  }
  string ans = s.substr(0, k);
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  while (T--) solve();
  return 0;
}
