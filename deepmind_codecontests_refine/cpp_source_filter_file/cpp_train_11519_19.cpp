#include <bits/stdc++.h>
using namespace std;
int a[10001];
int n, m, k;
int main(void) {
  int i;
  while (scanf("%d%d%d", &n, &m, &k) != EOF) {
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    if (n % 2 == 0) {
      printf("0\n");
      continue;
    }
    if (n % 2 && m < n / 2 + 1) {
      printf("0\n");
      continue;
    }
    int minn = 999999999;
    for (i = 1; i <= n; i += 2) {
      minn = min(a[i], minn);
    }
    int ci = m / (n / 2 + 1);
    int num = minn / ci + (minn % ci ? 1 : 0);
    if (k >= num) {
      cout << num * ci << endl;
    } else {
      cout << k * ci << endl;
    }
  }
  return 0;
}
