#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
char s[maxn];
bool check(int l, int r) {
  while (s[l] == s[r]) {
    l++;
    r--;
  }
  return l >= r;
}
int main() {
  int t;
  int len;
  int l, r;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int len = strlen(s);
    if (len == 1) {
      printf("%c\n", s[0]);
      continue;
    }
    l = 0, r = strlen(s) - 1;
    while (s[l] == s[r]) {
      l++;
      r--;
    }
    if (l >= r) {
      printf("%s", s);
      continue;
    }
    l--;
    r++;
    int i = l + 1, j = r - 1;
    int k0, k1;
    for (k0 = j; k0 >= i; k0--) {
      if (check(i, k0)) break;
    }
    for (k1 = i; k1 <= j; k1++) {
      if (check(k1, j)) break;
    }
    if (j - k1 + 1 > k0 - i + 1) {
      for (int o = 0; o <= l; o++) printf("%c", s[o]);
      for (int o = k1; o < len; o++) printf("%c", s[o]);
    } else {
      for (int o = 0; o <= k0; o++) printf("%c", s[o]);
      for (int o = r; o < len; o++) printf("%c", s[o]);
    }
    printf("\n");
  }
}
