#include <bits/stdc++.h>
using namespace std;
int n, a[200003], b[200003], sl[200003], f, l, c[200003], can[200003];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = n; i < n + n; i++) a[i] = a[i - n], b[i] = b[i - n];
  for (int i = 0; i < n + n; i++) c[i] = a[i] - b[i];
  for (int i = 1; i < n + n; i++) c[i] += c[i - 1];
  f = 1;
  l = 0;
  for (int i = n + n - 1; i >= 0; i--) {
    while (f <= l && sl[f] >= i + n) f++;
    while (f <= l && c[sl[l]] >= c[i]) l--;
    sl[++l] = i;
    if (i > 0 && i <= n && c[sl[f]] >= c[i - 1])
      can[i] = 1;
    else if (i == 0 && c[sl[f]] >= 0)
      can[i] = 1;
  }
  for (int i = 0; i < n + n; i++) c[i] = a[i] - b[(i - 1 + n + n) % (n + n)];
  for (int i = 0; i < n; i++) swap(c[i], c[n + n - 1 - i]);
  for (int i = 1; i < n + n; i++) c[i] += c[i - 1];
  f = 1;
  l = 0;
  for (int i = n + n - 1; i >= 0; i--) {
    while (f <= l && sl[f] >= i + n) f++;
    while (f <= l && c[sl[l]] >= c[i]) l--;
    sl[++l] = i;
    if (i > 0 && i <= n && c[sl[f]] >= c[i - 1])
      can[n - 1 - i] = 1;
    else if (i == 0 && c[sl[f]] >= 0)
      can[n - 1 - i] = 1;
  }
  int ct = 0;
  for (int i = 0; i < n; i++)
    if (can[i] == 1) ct++;
  printf("%d\n", ct);
  for (int i = 0; i < n; i++)
    if (can[i]) printf("%d ", i + 1);
  return 0;
}
