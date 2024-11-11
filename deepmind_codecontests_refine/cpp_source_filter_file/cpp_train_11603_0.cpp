#include <bits/stdc++.h>
const double PI = acos(-1);
using namespace std;
int n, q, f;
vector<int> pr[100100];
bool pr1[100100];
long long fc[100100];
long long pw(long long x, long long p) {
  if (p == 0) return 1;
  long long z = pw(x, p / 2);
  z *= z;
  z %= 1000000007;
  if (p % 2 == 0) return z;
  z *= x;
  z %= 1000000007;
  return z;
}
long long inv(long long y) { return pw(y, 1000000007 - 2); }
long long c(long long x, long long y) {
  if (x < y) swap(x, y);
  long long r = fc[y] * fc[x - y];
  r %= 1000000007;
  r = fc[x] * inv(r);
  r %= 1000000007;
  return r;
}
long long mi(long long x) {
  x %= 1000000007;
  x += 1000000007;
  x %= 1000000007;
  return x;
}
int main() {
  for (int i = 2; i < 100100; i++)
    if (!pr1[i]) {
      for (int j = i; j < 100100; j += i) {
        pr1[j] = 1;
        pr[j].push_back(i);
      }
    }
  fc[0] = 1;
  for (int i = 1; i < 100100; i++) {
    fc[i] = fc[i - 1] * i;
    fc[i] %= 1000000007;
  }
  cin >> q;
  while (q--) {
    scanf("%d%d", &n, &f);
    long long res = c(n - 1, f - 1);
    int en = 1 << pr[n].size();
    for (int i = 1; i < en - 1; i++) {
      long long r1 = 1;
      bool b = 0;
      for (int j = 0; j < pr[n].size(); j++) {
        if (i & (1 << j)) {
          r1 *= pr[n][j];
          b = !b;
        }
      }
      if (n / r1 < f) continue;
      if (b) {
        res = mi(res - c(n / r1 - 1, f - 1));
      } else {
        res += c(n / r1 - 1, f - 1);
        res %= 1000000007;
      }
    }
    printf("%I64d\n", res);
  }
  return 0;
}
