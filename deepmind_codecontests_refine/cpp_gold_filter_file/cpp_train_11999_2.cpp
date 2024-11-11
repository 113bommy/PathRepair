#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.1415926535897;
long long exp(long long base, long long power, int p) {
  if (!base) return 0;
  long long t = exp(base, power / 2, p);
  if (power & 1)
    return t * t * base % p;
  else
    return t * t % p;
}
void solve() {
  string s;
  cin >> s;
  int c(0), c0(0), c1(0), n = s.length();
  set<string> st;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      c1++;
    else if (s[i] == '0')
      c0++;
    else
      c++;
  if (c != 0) {
    if (c1 + c > c0 + 1) st.insert("11");
    if (c1 < c0 + c) st.insert("00");
    if (abs(c1 - c0) == c) {
      if (c1 > c0) {
        if (s[n - 1] == '?' or s[n - 1] == '0')
          st.insert("10");
        else
          st.insert("01");
      } else {
        if (s[n - 1] == '?' or s[n - 1] == '1')
          st.insert("01");
        else
          st.insert("10");
      }
    }
    if (c1 == c0 + c + 1) {
      if (s[n - 1] == '?' or s[n - 1] == '0')
        st.insert("10");
      else
        st.insert("01");
    }
    if (c > abs(c1 - c0)) {
      if (c1 + c == c0 + 1) {
        if (s[n - 1] == '?' or s[n - 1] == '1')
          st.insert("01");
        else if (s[n - 1] == '0')
          st.insert("10");
      } else {
        if (s[n - 1] == '?') {
          st.insert("10");
          st.insert("01");
        } else if (s[n - 1] == '0')
          st.insert("10");
        else
          st.insert("01");
      }
    }
  } else {
    if (c1 > c0 + 1) st.insert("11");
    if (c1 < c0) st.insert("00");
    if (c1 == c0 or c1 == c0 + 1) {
      if (s[n - 1] == '0')
        st.insert("10");
      else
        st.insert("01");
    }
  }
  for (auto x : st) cout << x << "\n";
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
