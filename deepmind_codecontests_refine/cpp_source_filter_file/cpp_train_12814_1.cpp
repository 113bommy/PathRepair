#include <bits/stdc++.h>
using namespace std;
int pos(char *s, char c) {
  for (int i = 0; s[i]; ++i)
    if (s[i] == c) return i;
  return -1;
}
int a[200000], n, m, t[200000];
int main() {
  int n;
  cin >> n;
  char s[51], sc[51];
  cin >> s;
  strcpy(sc, s);
  char t[51], tc[51];
  cin >> t;
  strcpy(tc, t);
  int res = 0;
  for (int i = 0; i < n; ++i) {
    int rr = pos(s + i, t[i]);
    if (rr == -1) {
      cout << -1;
      return 0;
    }
    for (int j = rr - 1; j >= 0; --j) swap(s[i + j], s[i + j + 1]);
    res += rr;
  }
  cout << res << "\n";
  for (int i = 0; i < n; ++i) {
    int rr = pos(sc + i, tc[i]);
    if (rr == -1) {
      cout << -1;
      return 0;
    }
    for (int j = rr - 1; j >= 0; --j) {
      swap(sc[i + j], sc[i + j + 1]);
      cout << i + j << " ";
    }
  }
  return 0;
}
