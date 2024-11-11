#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int k;
string s;
int c[26];
int main() {
  memset(c, 0, sizeof(c));
  cin >> k >> s;
  for (int i = 0; i < (int)(s.size()); ++i) {
    c[s[i] - 'a']++;
  }
  for (int i = 0; i < (int)(26); ++i) {
    if (c[i] % k != 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  for (int i = 0; i < (int)(26); ++i) {
    c[i] /= k;
  }
  for (int ct = 0; ct < (int)(k); ++ct) {
    for (int i = 0; i < (int)(26); ++i) {
      for (int j = 0; j < (int)(c[i]); ++j) {
        putchar('a' + i);
      }
    }
  }
  putchar('\n');
  return 0;
}
