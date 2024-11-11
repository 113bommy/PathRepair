#include <bits/stdc++.h>
using namespace std;
int a[200200], b[200200];
int num[200200];
int z;
int get_cl(int x) {
  if (b[x] == -1) return z;
  return b[x];
}
bool ok(int x) {
  int r = x;
  while (x) {
    r = get_cl(min(x, r));
    if (!r) return 0;
    int d = min(num[r], x / r);
    x -= d * r;
    r--;
  }
  return 1;
}
int main() {
  int c, n;
  int num1 = 0, flag = 0;
  scanf("%d%d", &c, &n);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    num[x]++;
  }
  for (int i = 1; i <= c; i++) a[i] = num[i] ? i : a[i - 1];
  for (int i = 0; i < c + 1; i++) b[i] = a[i];
  for (int i = 1; i <= c; i++) {
    z = i;
    if (!num[i] && b[i] != -1)
      for (int j = i; j <= c && !num[j]; j++) b[i] = -1;
    num[i]++;
    if (!ok(c)) {
      printf("%d\n", i);
      return 0;
    }
    num[i]--;
    if (b[i] == -1) b[i] = a[i];
  }
  puts("Greed is good");
  return 0;
}
