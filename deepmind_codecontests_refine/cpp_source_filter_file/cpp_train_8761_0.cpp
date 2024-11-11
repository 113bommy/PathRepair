#include <bits/stdc++.h>
using namespace std;
int n, a[100010], l[100010], r[100010], sum[100010], k;
char s1[100010];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -f;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool check1() {
  for (int i = 1; i + k - 1 <= n; i++) {
    int x = sum[i - 1] + sum[n] - sum[i + k - 1];
    if (x + k == n || x == 0) return true;
  }
  return false;
}
bool check2() {
  if (k * 2 < n || k == 1) return false;
  for (int i = 2; i + k - 1 < n; i++) {
    if (l[i] != 1 || r[i + k] != n) return false;
  }
  return true;
}
int main() {
  n = read();
  k = read();
  cin >> (s1 + 1);
  l[0] = 1;
  for (int i = 1; i <= n; i++) {
    a[i] = s1[i] - '0';
    sum[i] = sum[i - 1] + a[i];
    l[i] = (a[i - 1] == a[i] ? l[i - 1] : 1);
  }
  r[n] = n;
  for (int i = n - 1; i >= 1; i--) r[i] = (a[i + 1] == a[i] ? r[i + 1] : i);
  if (check1()) {
    printf("tokitsukaze\n");
  } else if (check2())
    printf("quailty\n");
  else
    printf("once again\n");
  return 0;
}
