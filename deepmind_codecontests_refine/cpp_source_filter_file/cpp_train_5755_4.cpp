#include <bits/stdc++.h>
using namespace std;
int n, k;
int x[1000007];
int l[1000007], r[1000007];
void work() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
  }
  l[0] = 0;
  r[n + 1] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[0]);
  }
  if (n <= 2) {
    printf("%d\n", n);
    return;
  }
  sort(x + 1, x + n + 1);
  int pos = 1;
  for (int i = 1; i <= n; i++) {
    while (x[pos] < x[i] - k) {
      pos++;
    }
    l[i] = i - pos + 1;
    l[i] = max(l[i], l[i - 1]);
  }
  pos = n;
  for (int i = n; i > 0; i--) {
    while (x[pos] > x[i] + k) {
      pos--;
    }
    r[i] = pos - i + 1;
    r[i] = max(r[i], r[i + 1]);
  }
  int ans = 2;
  for (int i = 2; i <= n; i++) {
    ans = max(ans, l[i] + r[i + 1]);
  }
  printf("%d\n", ans);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    work();
  }
  return 0;
}
