#include <bits/stdc++.h>
using namespace std;
int lt[(int)2e5];
;
int ls[(int)2e5];
int cs[(int)2e5];
int ct[(int)2e5];
int main() {
  string s, t;
  cin >> s >> t;
  s = '0' + s;
  t = '0' + t;
  int cur = 0;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == 'A')
      cur++;
    else
      cur = 0;
    ls[i] = cur;
  }
  cur = 0;
  for (int i = 1; i < t.size(); i++) {
    if (t[i] == 'A')
      cur++;
    else
      cur = 0;
    lt[i] = cur;
  }
  for (int i = 1; i < s.size(); i++) {
    if (s[i] != 'A') cs[i]++;
    cs[i] += cs[i - 1];
  }
  for (int i = 1; i < t.size(); i++) {
    if (t[i] != 'A') ct[i]++;
    ct[i] += ct[i - 1];
  }
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b;
    int c, d;
    cin >> a >> b >> c >> d;
    int t1 = min(d - c + 1, lt[d]);
    int s1 = min(b - a + 1, ls[b]);
    int s2 = cs[b] - cs[a - 1];
    int t2 = ct[d] - ct[c - 1];
    if (t2 < s2 || t2 % 2 != s2 % 2) {
      cout << 0;
      continue;
    }
    if (t1 > s1) {
      cout << 0;
      return 0;
    }
    if (t2 == s2) {
      if (t1 % 3 == s1 % 3) {
        cout << 1;
        continue;
      } else {
        cout << 0;
        continue;
      }
    }
    if (t1 == s1) {
      if (s2 == 0) {
        cout << 0;
        continue;
      } else {
        cout << 1;
        continue;
      }
    }
    cout << 1;
  }
}
