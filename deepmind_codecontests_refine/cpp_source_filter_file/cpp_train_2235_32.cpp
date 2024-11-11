#include <bits/stdc++.h>
using namespace std;
int f(int a, int b) {
  int r = 0, d[20], nd = 0;
  for (; a; a /= b) d[nd++] = a % b;
  for (int i = 0; i < nd; i++) r *= b, r += d[nd - 1 - i];
  return r;
}
void run() {
  int a, b, mx = 0, ans = 0;
  cin >> a >> b;
  for (int c = a; c; c /= 10) mx = max(mx, c % 10);
  for (int c = b; c; c /= 10) mx = max(mx, c % 10);
  for (int c = f(a, mx + 1) + f(b, mx + 1); c; c /= mx + 1) ans++;
  cout << ans << endl;
}
int main() {
  run();
  return 0;
}
