#include <bits/stdc++.h>
using namespace std;
const int debug_ = 0;
const int maxn = 200000;
const long long inf = 998244353;
long long mul(long long a, long long b) {
  long long ret = 1;
  while (b) {
    if (b & 1) {
      ret = ret * a % inf;
    }
    a = a * a % inf;
    b >>= 1;
  }
  return ret;
}
long long f[maxn + 10], rev[maxn + 10];
long long C(int a, int b) { return f[a] * rev[a - b] % inf * rev[b] % inf; }
long long p2[maxn + 10], pk[maxn + 10];
void init(int k) {
  p2[0] = pk[0] = 1;
  for (int i = 1; i <= maxn + 2; ++i) {
    p2[i] = p2[i - 1] * 2 % inf;
    pk[i] = pk[i - 1] * k % inf;
  }
}
long long cal(int kk, int a, int b) {
  init(kk - 2);
  long long ret = 0, rev2 = mul(2, inf - 2);
  for (int k = 1; k <= b; ++k) {
    if (k & 1) {
      ret += C(b, k) * p2[k - 1] % inf * pk[b - k] % inf;
    } else {
      ret += C(b, k) * (p2[k] + inf - C(k, k / 2)) % inf * rev2 % inf *
             pk[b - k] % inf;
    }
  }
  return ret % inf * mul(kk, a) % inf;
}
long long cal2(int a, int b) {
  long long ret = 0;
  for (int k = 0; k * 2 < b; ++k) {
    ret += C(b, k);
  }
  return ret % inf * mul(2, a) % inf;
}
int s[maxn + 10];
int main() {
  f[0] = rev[0] = 1;
  for (int i = 1; i <= maxn + 2; ++i) {
    f[i] = f[i - 1] * i % inf;
    rev[i] = mul(f[i], inf - 2);
  }
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s[i]);
  }
  int a = 0;
  for (int i = 0; i < n; ++i) {
    a += (s[i] == s[(i + 1) % n]);
  }
  if (k == 1) {
    puts("0");
  } else if (k == 2) {
    cout << cal2(a, n - a) << endl;
  } else {
    cout << cal(k, a, n - a) << endl;
  }
  return 0;
}
