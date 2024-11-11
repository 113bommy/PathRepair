#include <bits/stdc++.h>
using namespace std;
long long n, a[1 << 11], b[1 << 11], L;
void r(int k) {
  if (k >= L) return;
  r(k * 2);
  r(k * 2 + 1);
  b[k] += max(b[k * 2], b[k * 2 + 1]);
}
long long s(int k, int x) {
  if (a[k] == x) return 0;
  if (k >= L) return x - a[k];
  long long y = x - b[k];
  return y + s(2 * k, x - a[k] - y) + s(2 * k + 1, x - a[k] - y);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie();
  cin >> n;
  L = 1 << n;
  for (int i = 2; i < 1 << (n + 1); i++) cin >> a[i];
  for (int i = 1; i < 1 << (n + 1); i++) b[i] = a[i];
  r(1);
  cout << s(1, b[1]);
}
