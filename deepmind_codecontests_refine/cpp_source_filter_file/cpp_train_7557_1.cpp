#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string good;
  cin >> good;
  set<char> goods;
  for (char c : good) goods.insert(c);
  string pat;
  cin >> pat;
  int n = pat.size();
  int t;
  cin >> t;
  int trig = 0;
  for (char c : pat)
    if (c == '*') trig = 1;
  while (t--) {
    string s;
    cin >> s;
    if (s.size() < n - 1) {
      cout << "NO\n";
      continue;
    }
    if (trig) {
      int siz = s.size() - n + 1;
      int flag = 0;
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        if (pat[i] == '?') {
          if (!goods.count(s[i + cnt])) flag = 1;
        } else if (pat[i] != '*') {
          if (s[i + cnt] != pat[i]) flag = 1;
        } else {
          for (int j = i; j - i < siz; j++) {
            if (goods.count(s[j])) flag = 1;
          }
          cnt += siz;
        }
      }
      cout << (flag ? "NO" : "YES") << "\n";
    } else {
      if (s.size() == n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
          if (pat[i] == '?') {
            if (!goods.count(s[i])) flag = 1;
          } else {
            if (s[i] != pat[i]) flag = 1;
          }
        }
        cout << (flag ? "NO" : "YES") << "\n";
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
