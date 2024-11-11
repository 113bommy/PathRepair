#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const int n_ = 1e5 + 5;
int n, k, q[101], p[101], a[101], b[101];
bool ok() {
  for (int i = 1; i <= n; i++)
    if (a[i] != p[i]) return 0;
  return 1;
}
void make() {
  for (int i = 1; i <= n; i++) b[i] = a[q[i]];
  for (int i = 1; i <= n; i++) a[i] = b[i];
}
void roll() {
  for (int i = 1; i <= n; i++) b[q[i]] = a[i];
  for (int i = 1; i <= n; i++) a[i] = b[i];
}
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", q + i);
  for (int i = 1; i <= n; i++) scanf("%d", p + i);
  for (int i = 1; i <= n; i++) {
    if (i != p[i]) break;
    if (i == n) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) a[i] = i;
  int tmp = k;
  while (!ok() && tmp) {
    make();
    --tmp;
  }
  if (ok() && !(tmp & 1)) {
    roll();
    roll();
    if (!ok || !tmp) {
      puts("YES");
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) a[i] = i;
  tmp = k;
  while (!ok() && tmp) {
    roll();
    --tmp;
  }
  if (ok() && !(tmp & 1)) {
    make();
    make();
    if (!ok || !tmp) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}
