#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:20000000")
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
long long rll() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int n, u, r;
int best_res[35];
long long ans;
int a[35];
int b[35];
int p[35];
int k[35];
void go(int pos, bool ok) {
  if (pos == u + 1 || pos % 2 == 1) {
    long long now = 0;
    for (int i = (int)(1); i <= (int)(n); i++) now += (long long)a[i] * k[i];
    if (now > ans) ans = now;
  }
  if (pos == u + 1) return;
  if (!ok) {
    int *temp = new int[n + 1];
    for (int i = (int)(1); i <= (int)(n); i++) temp[i] = a[i];
    for (int i = (int)(1); i <= (int)(n); i++) a[i] ^= b[i];
    go(pos + 1, true);
    for (int i = (int)(1); i <= (int)(n); i++) a[i] = temp[i];
    delete[] temp;
  }
  int *temp = new int[n + 1];
  for (int i = (int)(1); i <= (int)(n); i++) temp[i] = a[i];
  for (int i = (int)(1); i <= (int)(n); i++) a[i] = temp[p[i]] + r;
  go(pos + 1, false);
  for (int i = (int)(1); i <= (int)(n); i++) a[i] = temp[i];
  delete[] temp;
}
void solve() {
  ans = -2e16;
  n = ri(), u = ri(), r = ri();
  for (int i = (int)(1); i <= (int)(n); i++) a[i] = ri();
  for (int i = (int)(1); i <= (int)(n); i++) b[i] = ri();
  for (int i = (int)(1); i <= (int)(n); i++) k[i] = ri();
  for (int i = (int)(1); i <= (int)(n); i++) p[i] = ri();
  int zero = 0;
  for (int i = (int)(1); i <= (int)(n); i++) zero += a[i] < 0;
  go(1, false);
  cout << ans << endl;
}
int main() {
  solve();
  return 0;
}
