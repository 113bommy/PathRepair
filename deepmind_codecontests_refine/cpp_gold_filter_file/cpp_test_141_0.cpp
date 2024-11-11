#include <bits/stdc++.h>
using namespace std;
bool m;
string rvrs(string k) {
  string q = "";
  m = 0;
  for (int i = k.length() - 1; i >= 0; i--) {
    if (k[i] != '0') m = 1;
    if (m) q += k[i];
  }
  if (m == 0)
    return "0";
  else
    return q;
}
string eval(string a, string b) {
  int l_a = a.length() - 1, l_b = b.length() - 1;
  for (int i = 0; i < l_b - l_a; i++) {
    string q = "0";
    a = q + a;
  }
  return a;
}
string sub(string b, string a, int lim) {
  int l_a = a.length() - 1, l_b = b.length() - 1;
  string c = "";
  int i = l_a, j = l_b;
  while (i >= 0 && j >= 0) {
    int q = b[j] - '0';
    int p = a[i] - '0';
    if (q >= p) {
      c += char((q - p) + '0');
    } else if (q < p) {
      j--;
      q += 10 * (b[j] - '0');
      if (b[j] != '1') return "-1";
      c += char((q - p) + '0');
    }
    i--;
    j--;
    if (j < 0 && i >= lim) return "-1";
  }
  return c;
}
int main() {
  string s;
  string a;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> a >> s;
    string ans = sub(s, eval(a, s), s.length() - a.length());
    if (ans != "-1")
      cout << rvrs(ans);
    else
      cout << ans;
    cout << endl;
  }
}
