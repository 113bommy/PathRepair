#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
bool isPrime(long long a) {
  long long i;
  for (i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      return 0;
    }
  }
  return (a != 1);
}
bool isPalindrom(const string &s, int l, int r) {
  for (int i = 0; i < (r - l + 1) / 2; i++) {
    if (s[l + i] != s[r - i]) {
      return 0;
    }
  }
  return 1;
}
template <class type1>
type1 gcd(type1 a, type1 b) {
  type1 t;
  while (b) {
    t = b;
    b = a % b;
    a = t;
  }
  return a;
}
long long positiveMod(long long v, long long md) {
  v = v % md;
  if (v < 0) {
    v += md;
  }
  return v;
}
void solve() {
  long long a, b, m, n, i, j, exSum, ta, dif, oneSum, k, tsum;
  cin >> a >> b >> m;
  if (a == b) {
    cout << 1 << " " << a << "\n";
    return;
  }
  if (b - a <= m) {
    cout << 2 << " " << a << " " << b << "\n";
    return;
  }
  for (i = 2; i <= 50; i++) {
    vector<long long> res(i + 1);
    exSum = a;
    ta = a;
    for (j = 1; j <= i; j++) {
      ta = exSum;
      ta++;
      exSum += ta;
      if (ta > b) {
        break;
      }
    }
    if (ta > b) {
      break;
    }
    exSum = a;
    ta = a;
    for (j = 1; j <= i; j++) {
      ta = exSum;
      ta += m;
      exSum += ta;
      if (ta >= b) {
        break;
      }
    }
    if (ta < b) {
      continue;
    }
    exSum = a;
    ta = a;
    for (j = 1; j <= i; j++) {
      ta = exSum;
      ta++;
      exSum += ta;
    }
    dif = b - ta;
    tsum = a;
    res[0] = a;
    for (j = 1; j <= i; j++) {
      if (i == j) {
        oneSum = 1;
      } else {
        oneSum = (1 << (i - j - 1));
      }
      k = dif / oneSum;
      k = min(m - 1, k);
      dif -= k * oneSum;
      res[j] = tsum + k + 1;
      tsum += res[j];
    }
    cout << i + 1 << " ";
    for (auto it : res) {
      cout << it << " ";
    }
    cout << "\n";
    return;
  }
  cout << -1 << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t, tt;
  cin >> tt;
  for (t = 0; t < tt; t++) {
    solve();
  }
  return 0;
}
