#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
bool debug = false;
long long H, M, h1, m1, h2, m2, y;
long long p[20];
long long f(long long hh, long long mm) {
  long long t = hh * ((M - 1) / p[k - 1]) + (mm) / p[k - 1];
  long long tmp = k - y - 1;
  if (tmp < 0) tmp = 0;
  t += (hh) / p[tmp];
  return t;
}
int main() {
  p[0] = 1;
  for (int i = 1; i < 20; i++) p[i] = 10 * p[i - 1];
  cin >> H >> M >> k;
  cin >> h1 >> m1 >> h2 >> m2;
  long long x = M - 1;
  while (x > 0) {
    if (x % 10 != 0) y++;
    x /= 10;
  }
  long long ty = y;
  x = H - 1;
  while (x > 0) {
    if (x % 10 != 0) ty++;
    x /= 10;
  }
  if (h1 * M + m1 > h2 * M + m2) {
    cout << f(h2, m2) + f(H - 1, M - 1) - f(h1, m1) + (ty >= k) << endl;
  } else
    cout << f(h2, m2) - f(h1, m1) << endl;
  return 0;
}
