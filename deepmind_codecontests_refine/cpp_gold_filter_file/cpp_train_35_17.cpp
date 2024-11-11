#include <bits/stdc++.h>
using namespace std;
const int N = int(2e5 + 5);
const int INF = 1e9 + 7;
int d[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string s;
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
int calc(string x) {
  string t = x + '#' + s;
  vector<int> p = prefix_function(t);
  int res = 0;
  for (int i : p) {
    if (i == x.size()) {
      ++res;
    }
  }
  return res;
}
string get(int a, int b, int c) {
  string res, res1, res2, res3;
  if (c < 10) {
    res += '0';
  }
  while (c) {
    int x = c % 10;
    res1 += char(x + '0');
    c /= 10;
  }
  reverse(res1.begin(), res1.end());
  res += res1;
  res += '-';
  if (b < 10) {
    res += '0';
  }
  while (b) {
    int x = b % 10;
    res2 += char(x + '0');
    b /= 10;
  }
  reverse(res2.begin(), res2.end());
  res += res2;
  res += '-';
  while (a) {
    int x = a % 10;
    res3 += char(x + '0');
    a /= 10;
  }
  reverse(res3.begin(), res3.end());
  res += res3;
  return res;
}
int main() {
  cin >> s;
  string ans;
  int mx = 0;
  for (int i = 2013; i <= 2015; ++i) {
    for (int j = 1; j <= 12; ++j) {
      for (int t = 1; t <= d[j - 1]; ++t) {
        string cur = get(i, j, t);
        if (calc(cur) > mx) {
          mx = calc(cur);
          ans = cur;
        }
      }
    }
  }
  cout << ans;
  return 0;
}
