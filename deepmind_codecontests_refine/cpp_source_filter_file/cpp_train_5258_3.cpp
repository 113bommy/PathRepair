#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 1000000000;
const ll mxr = 1e6 + 10;
int req(int cnt, int t) {
  for (int i = 1; i <= t; i++) {
    if (cnt - i == (2 * (t - i))) return i;
  }
  return -1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, cnt = 0, t;
  cin >> n >> t;
  string s1, s2;
  cin >> s1 >> s2;
  for (int i = 0; i < n; i++)
    if (s1[i] != s2[i]) cnt++;
  string ans = "";
  if (cnt <= t) {
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i])
        ans += s1[i];
      else if (t) {
        if (s1[i] != 'a' && s2[i] != 'a')
          ans += 'a';
        else if (s1[i] != 'b' && s2[i] != 'b')
          ans += 'b';
        else if (s1[i] != 'c' && s2[i] != 'c')
          ans += 'c';
        t--;
      }
    }
    if (t) {
      for (int i = 0; i < n; i++) {
        if (ans[i] == s1[i] && ans[i] == s2[i] && t) {
          if (s1[i] != 'a' && s2[i] != 'a')
            ans[i] = 'a';
          else if (s1[i] != 'b' && s2[i] != 'b')
            ans[i] = 'b';
          else if (s1[i] != 'c' && s2[i] != 'c')
            ans[i] = 'c';
          t--;
        }
      }
    }
  } else {
    int p = req(cnt, t);
    if (p == -1) {
      cout << p;
      return 0;
    }
    int rr = (cnt - p) / 2, fo = 0, ft = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (fo < rr) {
          ans += s1[i];
          fo++;
        } else if (ft < rr) {
          ans += s2[i];
          ft++;
        } else {
          if (s1[i] != 'a' && s2[i] != 'a')
            ans += 'a';
          else if (s1[i] != 'b' && s2[i] != 'b')
            ans += 'b';
          else if (s1[i] != 'c' && s2[i] != 'c')
            ans += 'c';
        }
      } else
        ans += s1[i];
    }
  }
  cout << ans << "\n";
  return 0;
}
