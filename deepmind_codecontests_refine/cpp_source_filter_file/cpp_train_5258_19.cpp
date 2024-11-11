#include <bits/stdc++.h>
using namespace std;
int n, t;
char s1[100005], s2[100005];
char findch(char a, char b) {
  for (char c = 'a';; c++) {
    if (c != a && c != b) {
      return c;
    }
  }
}
int main() {
  scanf("%d%d%s%s", &n, &t, s1, s2);
  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (s1[i] != s2[i]) {
      diff++;
    }
  }
  if (t >= diff) {
    int crt = 0;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i] && crt < n - t) {
        crt++;
        continue;
      }
      s1[i] = findch(s1[i], s2[i]);
    }
    puts(s1);
  } else if (t >= diff / 2 && t) {
    int crt1 = 0, crt2 = diff;
    for (int i = 0; i < n; i++) {
      if (s1[i] != s2[i]) {
        if (crt1 < t && crt2 > t) {
          s1[i] = s2[i];
          crt1++;
          crt2--;
        } else if (crt1 < t) {
          s1[i] = findch(s1[i], s2[i]);
          crt1++;
        }
      }
    }
    puts(s1);
  } else {
    puts("-1");
  }
}
