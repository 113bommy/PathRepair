#include <bits/stdc++.h>
using namespace std;
int n;
long long f[100005], g[100005], ff[100005], gg[100005];
int a[100005];
void dp() {
  f[1] = 0;
  ff[1] = 0;
  for (int i = (2); i <= (n); i++) {
    if (a[i - 1] < 2)
      f[i] = 0;
    else {
      int x = a[i - 1] - 2;
      if (x % 2) x--;
      f[i] = f[i - 1] + x + 2;
    }
    if (a[i - 1] == 0)
      ff[i] = 0;
    else {
      int x = a[i - 1] - 1;
      if (x % 2) x--;
      ff[i] = ff[i - 1] + x + 1;
      ff[i] = max(ff[i], f[i]);
      ff[i] = max(ff[i], (long long)a[i - 1]);
    }
  }
  g[n] = 0;
  gg[n] = 0;
  for (int i = (n - 1); i >= (1); i--) {
    if (a[i] < 2)
      g[i] = 0;
    else {
      int x = a[i] - 2;
      if (x % 2) x--;
      g[i] = g[i + 1] + x + 2;
    }
    if (a[i] == 0)
      gg[i] = 0;
    else {
      int x = a[i] - 1;
      if (x % 2) x--;
      gg[i] = gg[i - 1] + x + 1;
      gg[i] = max(gg[i], g[i]);
      gg[i] = max(gg[i], (long long)a[i]);
    }
  }
}
long long calc(int n) {
  if (n % 2) return n - 1;
  return n;
}
void get() {
  long long res = 0;
  for (int i = (1); i <= (n); i++) {
    if (a[i] > 0) res = max(res, f[i] + g[i] + a[i]);
    if (a[i] == 0) {
      res = max(res, ff[i]);
    } else {
      res = max(res, f[i] + calc(a[i]) + gg[i + 1]);
      res = max(res, f[i] + a[i]);
    }
    if (a[i - 1] == 0) {
      res = max(res, gg[i]);
    } else {
      res = max(res, g[i] + calc(a[i - 1]) + ff[i - 1]);
      res = max(res, g[i] + a[i - 1]);
    }
  }
  cout << res << endl;
}
int main() {
  scanf("%d", &n);
  for (int i = (1); i <= (n - 1); i++) scanf("%d", &a[i]);
  dp();
  get();
  return 0;
}
