#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 5;
int a[maxn];
double d[maxn * maxn];
int main() {
  int n, cnt;
  while (~scanf("%d", &n)) {
    cnt = 0;
    for (int i = 0; i < n; i++) scanf("%d", a + i);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (a[i] > a[j]) cnt++;
      }
    }
    d[0] = 0;
    d[1] = 1;
    for (int i = 2; i <= cnt; i++) d[i] = 4 + d[i - 2];
    printf("%.6f\n", d[cnt]);
  }
  return 0;
}
