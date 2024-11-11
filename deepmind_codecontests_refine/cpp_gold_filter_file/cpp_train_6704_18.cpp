#include <bits/stdc++.h>
using namespace std;
long long qu[128];
bool check(long long x, int k, long long n) {
  return x > 0 && x % 2 && x * ((1LL << k) - 1) + x * (x - 1) / 2 == n;
}
int main() {
  long long n;
  cin >> n;
  int cnt = 0;
  for (int k = 0; 1LL << k <= n + 1; k++) {
    long long b = (1LL << k + 1) - 3;
    long long c = -2 * n;
    long long d = roundl(sqrtl((long double)b * b - 4 * c));
    long long x1 = (-b + d) / 2;
    long long x2 = (-b - d) / 2;
    if (check(x1, k, n)) qu[cnt++] = x1 << k;
    if (check(x2, k, n)) qu[cnt++] = x2 << k;
  }
  if (cnt == 0) {
    cout << "-1\n";
    return 0;
  }
  sort(qu, qu + cnt);
  long long x_ = 0;
  for (int h = 0; h < cnt; h++) {
    if (qu[h] != x_) cout << qu[h] << '\n';
    x_ = qu[h];
  }
  return 0;
}
