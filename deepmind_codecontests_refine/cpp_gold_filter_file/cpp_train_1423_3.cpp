#include <bits/stdc++.h>
using namespace std;
map<int, int> b;
int a[5005], t[5005], cnt = 0, flag[5005], ans[5005];
void g(int n) {
  for (int i = 2; i; i++) {
    long long k = i * i;
    if (k > a[n] && a[n] >= 0) return;
    if (k > abs(a[n]) && a[n] < 0) return;
    while (a[n] % k == 0) a[n] /= k;
  }
}
int main() {
  memset(ans, 0, sizeof(ans));
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    g(i);
    if (!b[a[i]]) {
      b[a[i]] = ++cnt;
      t[i] = b[a[i]];
    } else
      t[i] = b[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    memset(flag, 0, sizeof(flag));
    int s = 0;
    for (int j = i; j <= n; j++) {
      if (a[j]) {
        if (!flag[t[j]]) {
          flag[t[j]] = 1;
          s++;
        }
      }
      ans[max(1, s)]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    printf("%d ", ans[i]);
  }
  return 0;
}
