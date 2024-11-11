#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
int n, m;
string s;
int main() {
  ios::sync_with_stdio(false);
  while (cin >> n >> m) {
    cin >> s;
    int max0 = 0;
    for (int i = 0; i < n; i++) {
      max0 += max(fabs(26 + 'a' - s[i]), fabs(s[i] - '0'));
    }
    if (max0 < m) {
      printf("-1\n");
      continue;
    }
    for (int i = 0; i < n; i++) {
      int fr = s[i] - 'a';
      int la = 26 + 'a' - s[i];
      if (la > fr) {
        if (la < m) {
          printf("z");
          m -= la;
        } else {
          printf("%c", s[i] + m);
          m = 0;
        }
      } else {
        if (fr < m) {
          printf("a");
          m -= fr;
        } else {
          printf("%c", s[i] - m);
          m = 0;
        }
      }
    }
    printf("\n");
  }
  return 0;
}
