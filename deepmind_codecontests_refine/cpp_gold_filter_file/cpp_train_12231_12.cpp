#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) f = ch == '-' ? -1 : f, ch = getchar();
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return x * f;
}
const int N = 200050;
long long tag[N];
int a[N];
int n;
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) a[i] = read();
  for (int i = 2; i <= n; ++i) {
    for (int st = 1, en, x; st <= i - 2; st = en + 1)
      x = (i - 2) / st, en = (i - 2) / x, tag[st] += a[i] < a[x + 1],
      tag[en + 1] -= a[i] < a[x + 1];
    tag[i - 1] += a[i] < a[1], tag[n] -= a[i] < a[1];
  }
  for (int i = 1; i < n; ++i) printf("%I64d ", tag[i] += tag[i - 1]);
  printf("\n");
  return 0;
}
