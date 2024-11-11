#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 100;
int p[N];
int kmp(string s) {
  memset(p, 0, sizeof 0);
  int n = s.size();
  for (int i = 1; i < n; i++) {
    int j = p[i - 1];
    while (j > 0 and s[i] != s[j]) {
      j = p[j - 1];
    }
    if (s[i] == s[j]) j++;
    p[i] = j;
  }
  return p[n - 1];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int m = kmp(t);
  int zs = 0, os = 0, zt = 0, ot = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0')
      zs++;
    else
      os++;
  }
  for (int i = 0; i < t.size(); i++) {
    if (t[i] == '0')
      zt++;
    else
      ot++;
  }
  if (zs < zt or os < ot) {
    cout << s;
    return 0;
  }
  string res = t;
  zs -= zt;
  os -= ot;
  string vanga;
  int zv = 0, ov = 0;
  for (int i = m; i < t.size(); i++) {
    vanga.push_back(t[i]);
    if (t[i] == '0')
      zv++;
    else
      ov++;
  }
  while (zs >= zv && os >= ov) {
    res += vanga;
    zs -= zv;
    os -= os;
  }
  while (zs--) res.push_back('0');
  while (os--) res.push_back('1');
  cout << res << endl;
  return 0;
}
