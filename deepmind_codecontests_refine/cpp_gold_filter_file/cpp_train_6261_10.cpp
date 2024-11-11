#include <bits/stdc++.h>
using namespace std;
int presuf(string s) {
  int n = s.length();
  int lps[n];
  lps[0] = 0;
  int len = 0;
  int i = 1;
  while (i < n) {
    if (s[i] == s[len]) {
      len++;
      lps[i] = len;
      i++;
    } else {
      if (len != 0)
        len = lps[len - 1];
      else {
        lps[i] = 0;
        i++;
      }
    }
  }
  int res = lps[n - 1];
  return (res > (n + 1) / 2) ? n / 2 : res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, m;
  string a = "", b = "";
  cin >> a >> b;
  n = a.size();
  m = b.size();
  int l = 0, r = m - 1, preind = -1;
  string pre = "", suf = "";
  preind = presuf(b) - 1;
  int ones = 0, zeros = 0, tones = 0, tzeros = 0;
  for (int i = 0; i < n; i++) {
    ones += (a[i] == '1');
    zeros += (a[i] == '0');
  }
  for (int i = 0; i < m; i++) {
    tones += (b[i] == '1');
    tzeros += (b[i] == '0');
  }
  if ((m > n) || (ones < tones) || (zeros < tzeros)) {
    cout << a;
    return 0;
  }
  string suffix = "";
  long long int sones = 0, szeros = 0;
  for (int i = preind + 1; i < m; i++) {
    suffix += b[i];
    sones += (b[i] == '1');
    szeros += (b[i] == '0');
  }
  ones -= tones;
  zeros -= tzeros;
  cout << b;
  while (ones >= sones && zeros >= szeros) {
    cout << suffix;
    ones -= sones;
    zeros -= szeros;
  }
  while (ones--) cout << '1';
  while (zeros--) cout << '0';
}
