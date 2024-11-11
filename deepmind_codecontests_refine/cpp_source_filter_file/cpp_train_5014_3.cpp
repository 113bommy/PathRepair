#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin >> s;
  vector<char> b;
  vector<char> e;
  if (s.size() == 0) {
    cout << "";
    return 0;
  }
  if (s.size() <= 3) {
    cout << s[0];
    return 0;
  }
  long long p1 = 0, p2 = s.size() - 1;
  while (p2 > p1) {
    if (s[p1] == s[p2]) {
      if (p1 == p2) {
        b.push_back(s[p1]);
      } else {
        b.push_back(s[p1]);
        e.push_back(s[p2]);
      }
      p1 += 1, p2 -= 1;
    } else {
      if (s[p1 + 1] == s[p2]) {
        p1 += 1;
      } else {
        p2 -= 1;
      }
    }
  }
  if (b.size() + e.size() < s.size() / 2) {
    cout << "IMPOSSIBLE";
  } else {
    for (char c : b) {
      cout << c;
    }
    reverse(e.begin(), e.end());
    for (char c : e) {
      cout << c;
    }
  }
}
