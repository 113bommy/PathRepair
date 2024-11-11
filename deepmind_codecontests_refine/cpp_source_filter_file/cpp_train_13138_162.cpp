#include <bits/stdc++.h>
using namespace std;
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void solve() {
  string s;
  cin >> s;
  vector<int> p = prefix_function(s);
  long long int n = s.length();
  if (n <= 2) {
    cout << "Just a legend" << endl;
    return;
  }
  if (p[n - 1] == 0) {
    cout << "Just a legend" << endl;
    return;
  }
  long long int ans = p[n - 1];
  bool found = false;
  for (long long int i = 1; i < n - 1; i++) {
    if (p[i] == p[n - 1]) {
      found = true;
      break;
    }
  }
  if (found) {
    for (long long int i = 0; i < ans; i++) {
      cout << s[i];
    }
    cout << endl;
  } else {
    if (p[p[n - 1]] == 0) {
      cout << "Just a legend" << endl;
      return;
    } else {
      ans = p[p[n - 1] - 1];
      for (long long int i = 0; i < ans; i++) {
        cout << s[i];
      }
      cout << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
