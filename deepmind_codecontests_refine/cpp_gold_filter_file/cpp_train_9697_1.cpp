#include <bits/stdc++.h>
using namespace std;
int a[200050];
int n, k;
long long b[200050][2], res = 1;
void func(int cnt, int st, int ed) {
  if (!cnt) return;
  if (ed < 0) {
    res = res * (k - (st > 0)) % 998244353;
    for (int i = 1; i < cnt; i++) res = res * (k - 1) % 998244353;
    return;
  }
  b[0][0] = k - 1;
  b[0][1] = 1;
  if (st > 0) b[0][0]--;
  if (st == ed) b[0][0]++, b[0][1] = 0;
  for (int i = 0; i < cnt - 1; i++) {
    b[i + 1][0] =
        (b[i][1] * (k - 1) % 998244353 + b[i][0] * (k - 2)) % 998244353;
    b[i + 1][1] = b[i][0];
  }
  res = res * b[cnt - 1][0] % 998244353;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  bool f = false;
  for (int i = 2; i < n; i++)
    if (a[i] == a[i - 2] && a[i] > 0) {
      f = true;
      break;
    }
  if (f) {
    puts("0");
    return 0;
  }
  int cnt = 0;
  int pre = -1;
  for (int i = 0; i < n; i += 2) {
    if (a[i] < 0)
      cnt++;
    else {
      func(cnt, pre, a[i]);
      cnt = 0;
      pre = a[i];
    }
  }
  func(cnt, pre, -1);
  cnt = 0;
  pre = -1;
  for (int i = 1; i < n; i += 2) {
    if (a[i] < 0)
      cnt++;
    else {
      func(cnt, pre, a[i]);
      cnt = 0;
      pre = a[i];
    }
  }
  func(cnt, pre, -1);
  printf("%lld\n", res);
  return 0;
}
