#include <bits/stdc++.h>
using namespace std;
int b1[1000004], a1[1000004], en[1000004], z[2000004], p[2000004];
string r(string a) {
  int n = a.length();
  for (int i = 0; i < n / 2; i++) swap(a[i], a[n - 1 - i]);
  return a;
}
int main() {
  ios::sync_with_stdio(0);
  string a, b;
  getline(cin, a);
  getline(cin, b);
  if (a.length() != b.length() or a.length() == 1) {
    cout << -1 << " " << -1;
    return 0;
  }
  int n = a.length();
  string ra = r(a);
  int i = 0;
  while (b[n - 1 - i] == a[i] and i < n) {
    en[n - 1 - i] = 1;
    i++;
  }
  string s = b + '\0' + a;
  int l = 0, r = 0, k;
  for (int i = 1; i <= 2 * n; i++) {
    z[i] = min(z[i - l], max(0, r - i));
    while (s[i + z[i]] == s[z[i]] and i + z[i] <= 2 * n) z[i]++;
    if (z[i] + i > r) {
      r = z[i] + i;
      l = i;
    }
  }
  en[n] = 1;
  string t = ra + '\0' + b;
  p[0] = 0;
  for (int i = 1; i <= 2 * n; i++) {
    k = p[i - 1];
    while (t[k] != t[i] and k > 0) {
      k = p[k - 1];
    }
    if (t[k] == t[i]) k++;
    p[i] = k;
  }
  pair<int, int> par = make_pair(-1, -1);
  for (int i = 1; i < n; i++) {
    if (en[n - i]) {
      int j = n - p[2 * n - i];
      if (z[n + i + 1] + i >= j) par = make_pair(i - 1, j);
    } else
      break;
  }
  cout << par.first << " " << par.second;
  return 0;
}
