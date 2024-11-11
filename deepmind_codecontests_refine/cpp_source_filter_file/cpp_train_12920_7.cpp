#include <bits/stdc++.h>
using namespace std;
map<char, long long> s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  bool p, q, t;
  p = q = t = 0;
  string str;
  for (long long i = 0; i < n; i++) {
    cin >> str;
    s['a'] = s['A'] = s['0'] = 0;
    p = q = t = 0;
    for (long long j = 0; j < str.size(); j++) {
      if (str[j] <= 'Z' && str[j] >= 'A') {
        s['A']++;
        p = 1;
      }
      if (str[j] <= 'z' && str[j] >= 'a') {
        s['a']++;
        q = 1;
      }
      if (str[j] <= '9' && str[j] >= '0') {
        s['0']++;
        t = 1;
      }
    }
    if (p && p && t) {
      cout << str << endl;
      continue;
    }
    if (!p && !q) {
      long long j = 0;
      for (j; j < str.size(); j++) {
        if (str[j] <= '9' && str[j] >= '0') {
          str[j] = 'a';
          break;
        }
      }
      for (j; j < str.size(); j++) {
        if (str[j] <= '9' && str[j] >= '0') {
          str[j] = 'A';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
    if (!p && !t) {
      long long j = 0;
      for (j; j < str.size(); j++) {
        if (str[j] <= 'Z' && str[j] >= 'A') {
          str[j] = 'a';
          break;
        }
      }
      for (j; j < str.size(); j++) {
        if (str[j] <= 'Z' && str[j] >= 'A') {
          str[j] = '0';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
    if (!p && !q) {
      long long j = 0;
      for (j; j < str.size(); j++) {
        if (str[j] <= 'z' && str[j] >= 'a') {
          str[j] = 'A';
          break;
        }
      }
      for (j; j < str.size(); j++) {
        if (str[j] <= 'z' && str[j] >= 'a') {
          str[j] = '0';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
    if (!p) {
      for (long long j = 0; j < str.size(); j++) {
        char ch;
        if (str[j] <= 'z' && str[j] >= 'a') ch = 'a';
        if (str[j] <= 'Z' && str[j] >= 'A') ch = 'A';
        if (str[j] <= '9' && str[j] >= '0') ch = '0';
        if (s[ch] > 1) {
          s[str[j]]--;
          str[j] = 'a';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
    if (!q) {
      for (long long j = 0; j < str.size(); j++) {
        char ch;
        if (str[j] <= 'z' && str[j] >= 'a') ch = 'a';
        if (str[j] <= 'Z' && str[j] >= 'A') ch = 'A';
        if (str[j] <= '9' && str[j] >= '0') ch = '0';
        if (s[ch] > 1) {
          str[j] = 'A';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
    if (!t) {
      for (long long j = 0; j < str.size(); j++) {
        char ch;
        if (str[j] <= 'z' && str[j] >= 'a') ch = 'a';
        if (str[j] <= 'Z' && str[j] >= 'A') ch = 'A';
        if (str[j] <= '9' && str[j] >= '0') ch = '0';
        if (s[ch] > 1) {
          str[j] = '0';
          break;
        }
      }
      cout << str << endl;
      continue;
    }
  }
  return 0;
}
