#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60777216")
using namespace std;
int n;
int s[111111];
int a[111111];
int r1[111111];
int r2[111111];
int main() {
  cin >> n;
  for (int i = (0); i < (n); i++) scanf("%d", s + i), a[i] = s[i];
  sort(a, a + n);
  int tn = n / 3;
  if (tn * 3 != n) tn++;
  for (int i = (0); i < (tn); i++) {
    r1[i] = 0;
    r2[i] = a[i];
  }
  for (int j = (tn); j < (2 * tn); j++) {
    r1[j] = a[j];
    r2[j] = 0;
  }
  int num = n - 2 * tn;
  for (int j = (2 * tn); j < (n); j++) {
    r1[j] = num - (j - 2 * tn) - 1;
    r2[j] = a[j] - r1[j];
  }
  puts("YES");
  for (int i = (0); i < (n); i++) {
    int pos = lower_bound(a, a + n, s[i]) - a;
    if (i) printf(" ");
    printf("%d", r1[i]);
  }
  puts("");
  for (int i = (0); i < (n); i++) {
    int pos = lower_bound(a, a + n, s[i]) - a;
    if (i) printf(" ");
    printf("%d", r2[i]);
  }
  puts("");
  return 0;
}
