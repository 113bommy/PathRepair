#include <bits/stdc++.h>
using namespace std;
const int N = 200100;
const int M = 200100;
const long long mod = 1e9 + 7;
struct Node {
  int post, date;
} a[N];
int solve(string p) {
  int b = 0;
  int ans = 0;
  for (int i = p.length() - 1; i >= 0; i--) {
    ans += (p[i] - '0') * (1 << b);
    b++;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long ans = 0;
    string s;
    cin >> s;
    int len = 0, k = 0;
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '0')
        len++;
      else if (s[i] == '1' && len) {
        a[++k].date = len;
        a[k].post = i;
        len = 0;
      }
    }
    for (int i = 0; i < s.length(); i++) {
      if (s[i] == '1') ans++;
      if (i != s.length() - 1 && s[i] == '1' && s[i + 1] == '0') ans++;
    }
    for (int i = 1; i <= k; i++) {
      int l = a[i].post;
      string b = "";
      for (int j = 0; j < 20; j++) {
        if (l + j >= s.length()) break;
        b += s[l + j];
        int c = solve(b) - j - 1;
        if (c <= a[i].date && c) ans++;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
