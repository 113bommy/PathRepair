#include <bits/stdc++.h>
using namespace std;
bool IsGood(char c) {
  if (c == '4' || c == '7') return true;
  return false;
}
vector<int> prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  for (int i = 1; i < n; ++i) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) ++j;
    pi[i] = j;
  }
  return pi;
}
int main() {
  int n, k, cnt = 0;
  cin >> n >> k;
  string str;
  cin >> str;
  for (int i = 0; i < n - 1; ++i) {
    if (cnt == k) break;
    if (str[i] == '4' && str[i + 1] == '7') {
      if (i % 2 == 0)
        str[i + 1] = '4';
      else {
        if (i > 0 && str[i - 1] == '4') {
          if ((k - cnt) % 2 == 1) str[i] = '7';
          cout << str << endl;
          return 0;
        } else
          str[i] = '7';
      }
      ++cnt;
    }
  }
  cout << str << endl;
  return 0;
}
