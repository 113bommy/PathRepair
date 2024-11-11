#include <bits/stdc++.h>
using namespace std;
bool checkstring(string p, string s) {
  long long int i, j, k, np, ns;
  np = p.size();
  ns = s.size();
  int a[26];
  for (j = 0; j < 26; j++) a[j] = 0;
  for (i = 0; i < np; i++) a[p[i] - 'a']++;
  for (i = 0; i <= ns - np; i++) {
    string x;
    int b[26];
    for (j = 0; j < 26; j++) b[j] = 0;
    int flag = 0;
    for (j = i; j < i + np; j++) x = x + s[j];
    for (k = 0; k < np; k++) b[x[k] - 'a']++;
    for (j = 0; j < 26; j++) {
      if (a[j] != b[j]) {
        flag = 1;
        break;
      }
    }
    if (flag == 0) return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int i, k, b, x, n, min, max;
    string p, s;
    cin >> p >> s;
    if (checkstring(p, s)) {
      cout << "YES\n";
    } else
      cout << "N0\n";
  }
}
