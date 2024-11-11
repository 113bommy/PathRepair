#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N], c[N];
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    scanf("%s%s", s, c);
    int mark = 1;
    for (int i = 0; i < m; i++) {
      if ((c[i] < 'a' || c[i] > 'z') && c[i] != '*') mark = 0;
    }
    if (mark == 0) {
      printf("NO\n");
      continue;
    }
    if (n > m + 1) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < n && s[i] != '*'; i++) {
      if (s[i] != c[i]) {
        mark = 0;
        break;
      }
    }
    if (mark == 0) {
      printf("NO\n");
      continue;
    }
    int l = m - 1;
    for (int i = n - 1; i >= 0 && s[i] != '*'; i--) {
      if (s[i] != c[l]) {
        mark = 0;
        break;
      }
      l--;
    }
    if (mark == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
}
