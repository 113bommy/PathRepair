#include <bits/stdc++.h>
const int N = 200001;
using namespace std;
int f(char c, int n) { return (c - '0') % 3 == n; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  int n = s.size();
  int sum = 0, one = 0, two = 0;
  for (char c : s) {
    sum += c - '0';
    one += f(c, 1);
    two += f(c, 2);
  }
  sum %= 3;
  if (sum == 0) {
    cout << s;
    return 0;
  }
  string ans;
  string s1;
  if (sum == 1) {
    if (one) {
      int cs = 1;
      for (int i = n - 1; i >= 0; i--) {
        if (f(s[i], 1) && cs) {
          cs = 0;
        } else {
          s1 += s[i];
        }
      }
      while (s1.size() > 1 && s1.back() == '0') {
        s1.pop_back();
      }
      if (!s1.empty()) {
        reverse(s1.begin(), s1.end());
        if (s1.size() > ans.size()) {
          ans = s1;
        }
      }
    }
    s1.clear();
    if (two > 1) {
      int cs = 2;
      for (int i = n - 1; i >= 0; i--) {
        if (f(s[i], 2) && cs) {
          --cs;
        } else {
          s1 += s[i];
        }
      }
      while (s1.size() > 1 && s1.back() == '0') {
        s1.pop_back();
      }
      if (!s1.empty()) {
        reverse(s1.begin(), s1.end());
        if (s1.size() > ans.size()) {
          ans = s1;
        }
      }
    }
  }
  s1.clear();
  if (sum == 2) {
    if (two) {
      int cs = 1;
      for (int i = n - 1; i >= 0; i--) {
        if (f(s[i], 2) && cs) {
          cs = 0;
        } else {
          s1 += s[i];
        }
      }
      while (s1.size() > 1 && s1.back() == '0') {
        s1.pop_back();
      }
      if (!s1.empty()) {
        reverse(s1.begin(), s1.end());
        if (s1.size() > ans.size()) {
          ans = s1;
        }
      }
    }
    s1.clear();
    if (one > 1) {
      int cs = 2;
      for (int i = n - 1; i >= 0; i--) {
        if (f(s[i], 1) && cs) {
          --cs;
        } else {
          s1 += s[i];
        }
      }
      while (s1.size() > 1 && s1.back() == '0') {
        s1.pop_back();
      }
      if (!s1.empty()) {
        reverse(s1.begin(), s1.end());
        if (s1.size() > ans.size()) {
          ans = s1;
        }
      }
    }
  }
  cout << (ans.empty() ? "-1" : ans);
}
