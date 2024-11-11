#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
vector<long long> prefix_function(string s) {
  long long n = s.size();
  vector<long long> pi(n);
  for (long long i = 1; i < n; ++i) {
    long long j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  vector<long long> p = prefix_function(s);
  long long e = p[p.size() - 1];
  if (e == 0)
    cout << "Just a legend";
  else {
    bool k = 0;
    for (long long i = 0; i < p.size() - 1; i++) {
      if (p[i] == e) {
        k = 1;
        cout << s.substr(0, e);
        break;
      }
    }
    if (!k) {
      e = p[e - 1];
      if (e == 0)
        cout << "Just a legend";
      else
        cout << s.substr(0, e);
    }
  }
}
