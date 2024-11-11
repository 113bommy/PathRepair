#include <bits/stdc++.h>
using namespace std;
int mod1 = int(1e9) + 7;
int a[110];
int main() {
  int n;
  scanf("%d", &(n));
  for (int i = 1; i <= (int)(n); ++i) scanf("%d", &(a[i]));
  int cnt = 0;
  while (1) {
    int mmax = 0, mi = -1;
    for (int i = 2; i <= n; i++) {
      if (a[i] > mmax) {
        mmax = a[i];
        mi = i;
      }
    }
    if (mmax < a[1]) break;
    a[mi]--;
    a[0]++;
    cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}
