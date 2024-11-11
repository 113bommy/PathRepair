#include <bits/stdc++.h>
using namespace std;
const int MAX_M = 200000, MAX_N = 200000;
int n, m;
int a[MAX_N];
int t[MAX_M + 1], r[MAX_M + 1];
int b[MAX_N];
int bl, br;
int main() {
  int s;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", a + i);
  }
  s = 0;
  for (int i = 0; i < m; i++) {
    int ti, ri;
    scanf("%d %d", &ti, &ri);
    while (s > 0 && ri >= r[s - 1]) s--;
    t[s] = ti;
    r[s] = ri;
    s++;
  }
  r[s] = 0;
  s++;
  bl = 0;
  br = r[0];
  for (int i = 0; i < br; i++) {
    b[i] = a[i];
  }
  sort(b, b + br);
  for (int i = 1; i < s; i++) {
    for (int j = r[i - 1]; j > r[i]; j--) {
      if (t[i - 1] == 1) {
        a[j - 1] = b[--br];
      } else {
        a[j - 1] = b[bl++];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (i) printf(" ");
    printf("%d", a[i]);
  }
  printf("\n");
  return 0;
}
