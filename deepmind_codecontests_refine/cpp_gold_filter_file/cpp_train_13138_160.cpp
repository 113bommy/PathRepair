#include <bits/stdc++.h>
using namespace std;
string s;
int cnt[3000000];
vector<int> p_fun(string s) {
  int n = s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (s[i] != s[j] && j > 0) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j++;
    cnt[j]++;
  }
  return pi;
}
int main() {
  cin >> s;
  vector<int> pi = p_fun(s);
  int n = s.length() - 1;
  int len = pi[n];
  if (len == 0) {
    cout << "Just a legend";
    return 0;
  }
  for (int i = 0; i < n - 1; ++i)
    if (pi[i] == len) {
      cout << s.substr(0, len);
      return 0;
    }
  len = pi[len - 1];
  if (len == 0) {
    cout << "Just a legend";
    return 0;
  }
  cout << s.substr(0, len);
  return 0;
}
