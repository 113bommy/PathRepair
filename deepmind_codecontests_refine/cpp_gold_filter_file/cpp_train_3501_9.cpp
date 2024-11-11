#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 1e5 + 10;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char s[MAXN];
  scanf("%s", s);
  for (int i = 0; i < m; i++) {
    int l, r;
    char ch1[5], ch2[5];
    scanf("%d%d%s%s", &l, &r, ch1, ch2);
    for (int i = l - 1; i < r; i++) {
      if (s[i] == ch1[0]) {
        s[i] = ch2[0];
      }
    }
  }
  printf("%s\n", s);
  return 0;
}
