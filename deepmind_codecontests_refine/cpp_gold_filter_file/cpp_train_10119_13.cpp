#include <bits/stdc++.h>
using namespace std;
string s[8];
int p[9], mas[10];
int k, n, ma, mi, ans = 1000000000;
int per(string s) {
  string st;
  st = s;
  for (int i = 0; i < k; i++) st[i] = s[p[i]];
  int a = 0;
  for (int i = 0; i < k; i++) a = a * 10 + st[i] - '0';
  return a;
}
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  for (int i = 0; i < k; i++) {
    p[i] = i;
  }
  do {
    for (int i = 0; i < n; i++) mas[i] = per(s[i]);
    ma = 0;
    mi = 1000000000;
    for (int j = 0; j < n; j++) {
      ma = max(ma, mas[j]);
      mi = min(mi, mas[j]);
    }
    ans = min(ans, ma - mi);
  } while (next_permutation(p, p + k));
  cout << ans;
  return 0;
}
