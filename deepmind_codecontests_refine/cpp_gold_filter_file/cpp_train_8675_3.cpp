#include <bits/stdc++.h>
using namespace std;
char s[100];
char s1[5][10] = {"UL", "UR", "DR", "DL", "ULDR"};
int f(int a) { return a > 0 ? a : -a; }
int main() {
  int n;
  while (~scanf("%d", &n)) {
    int i, j;
    long long a[6];
    memset(a, 0, sizeof(a));
    for (i = 0; i < n; i++) {
      scanf("%s", s);
      for (j = 0; j < 5; j++) {
        if (strcmp(s, s1[j]) == 0) a[j]++;
      }
    }
    if (a[0] < a[2]) swap(a[0], a[2]);
    if (a[1] < a[3]) swap(a[1], a[3]);
    printf("%I64d\n", (a[4] + a[0] + a[2] + 1) * (a[4] + a[1] + a[3] + 1));
  }
}
