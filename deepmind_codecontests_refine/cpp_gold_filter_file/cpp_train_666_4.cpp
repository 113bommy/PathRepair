#include <bits/stdc++.h>
using namespace std;
long long p;
long long n, m;
vector<int> Factorize(int num) {
  vector<int> res;
  for (int div = 2; div * div <= num; div++) {
    if (num % div == 0) {
      res.push_back(div);
      while (num % div == 0) {
        num /= div;
      }
    }
  }
  if (num != 1) {
    res.push_back(num);
  }
  return res;
}
long long Sum(long long num, long long div) {
  num -= num % div;
  return (num * (num / div + 1) / 2) % p;
}
long long Solve(long long x, long long y) {
  if (y <= 0) {
    return 0;
  }
  auto factors = Factorize(x);
  int f = factors.size();
  long long quan = 0;
  long long sum = 0;
  for (int mask = 0; mask < 1 << f; mask++) {
    bool odd = 0;
    long long div = 1;
    for (int i = 0; i < f; i++) {
      if (mask & 1 << i) {
        odd ^= 1;
        div *= factors[i];
      }
    }
    sum = ((sum + (odd ? -1 : 1) * Sum(y, div)) % p + p) % p;
    quan = quan + (odd ? -1 : 1) * y / div;
  }
  return ((m * quan - sum + quan) % p + p) % p;
}
int main() {
  ios_base::sync_with_stdio(false);
  long long l, r;
  cin >> n >> m >> l >> r >> p;
  long long res = 0;
  for (long long x = 1, ly = m, ry = m; x <= n; x++) {
    while (x * x + ly * ly >= l * l && ly > 0) {
      ly--;
    }
    while (x * x + ry * ry > r * r && ry > 0) {
      ry--;
    }
    res =
        ((res + 2LL * (n - x + 1) * (Solve(x, ry) - Solve(x, ly))) % p + p) % p;
  }
  res = (res + (l <= 1 ? (n + 1) * m + (m + 1) * n : 0)) % p;
  cout << res << "\n";
}
