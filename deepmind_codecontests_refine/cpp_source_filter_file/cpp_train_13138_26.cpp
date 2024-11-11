#include <bits/stdc++.h>
using namespace std;
const int P = 2017, M = 1e9 + 7;
string s;
int n;
vector<int> p, h;
int get(int l, int r) {
  if (!l) return h[r];
  return h[r] - h[l - 1] * p[r - l + 1];
}
int bs(int i) {
  int l = 0, r = n - i - 1;
  while (l != r - 1) {
    int m = (l + r) / 2;
    if (get(i, i + m - 1) == get(0, m - 1)) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}
int main() {
  cin >> s;
  n = s.size();
  if (s.size() < 3) {
    cout << "Just a legend";
    return 0;
  }
  if (s[0] == s[1] && s[1] == s[2] && s.size() == 3) {
    cout << s[0];
    return 0;
  } else if (s.size() == 3) {
    cout << "Just a legend";
    return 0;
  }
  p.resize(n);
  h.resize(n);
  p[0] = 1;
  for (int i = 1; i < n; i++) {
    p[i] = p[i - 1] * P;
  }
  h[0] = s[0] - 'a' + 1;
  for (int i = 1; i < n; i++) {
    h[i] = h[i - 1] * P + s[i] - 'a' + 1;
  }
  int ans = 0;
  for (int i = 1; i < n - 1; i++) {
    ans = max(ans, bs(i));
  }
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (get(i, n - 1) == get(0, n - i - 1)) {
      st.insert(n - i);
    }
  }
  if (ans == 0 || st.upper_bound(ans) == st.begin()) {
    cout << "Just a legend";
    return 0;
  }
  cout << s.substr(0, *(--st.upper_bound(ans)));
}
