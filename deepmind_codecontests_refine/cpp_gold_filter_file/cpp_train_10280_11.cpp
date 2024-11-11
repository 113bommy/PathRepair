#include <bits/stdc++.h>
using namespace std;
istream& operator>>(istream& in, vector<int>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
ostream& operator<<(ostream& out, vector<int>& a) {
  for (int i : a) out << i << ' ';
  return out;
}
istream& operator>>(istream& in, vector<long long>& a) {
  for (int i = 0; i < a.size(); ++i) in >> a[i];
  return in;
}
ostream& operator<<(ostream& out, vector<long long>& a) {
  for (long long i : a) out << i << ' ';
  return out;
}
istream& operator>>(istream& in, pair<int, int>& p) {
  in >> p.first >> p.second;
  return in;
}
ostream& operator<<(ostream& out, pair<int, int>& p) {
  out << p.first << ' ' << p.second;
  return out;
}
long long mod(long long a, long long b) { return (a % b + b) % b; }
long long gcd(long long a, long long b, long long& x, long long& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  long long x1, y1;
  long long d = gcd(mod(b, a), a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}
bool is_prime(long long n) {
  for (long long d = 2; d * d <= n; ++d)
    if (n % d == 0) return 0;
  return 1;
}
long long phi(long long n) {
  long long result = n;
  for (long long i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      while (n % i == 0) n /= i;
      result -= result / i;
    }
  if (n > 1) result -= result / n;
  return result;
}
long long obr(long long a, long long m, long long x = 1) {
  if ((a * x) % m == 1)
    return x;
  else
    return obr(a, m, (x * a) % m);
}
long long sum_d(long long n) {
  long long ans = 0;
  long long d = 1;
  for (; d * d < n; ++d)
    if (n % d == 0) {
      ans += d + n / d;
    }
  return ans + d * (n % d == 0 && d * d == n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.setf(ios::fixed);
  cout.precision(10);
  long long n, m, x, y, ux, uy;
  cin >> n >> m >> x >> y >> ux >> uy;
  long long t1, t2;
  if (ux == 1)
    t1 = n - x;
  else
    t1 = x;
  if (uy == 1)
    t2 = m - y;
  else
    t2 = y;
  if (x % n == 0) t1 = 0;
  if (y % m == 0) t2 = 0;
  if (ux == 0) {
    if (x % n) {
      cout << -1;
      return 0;
    } else {
      y = y + uy * t2;
      y = m * (mod(y / m, 2));
      cout << x << ' ' << y;
      return 0;
    }
  }
  if (uy == 0) {
    if (y % m) {
      cout << -1;
      return 0;
    } else {
      x = x + ux * t1;
      x = n * (mod(x / n, 2));
      cout << x << ' ' << y;
      return 0;
    }
  }
  long long t = t2 - t1;
  long long k, j;
  long long d = gcd(n, m, k, j);
  if (t % d) {
    cout << -1;
    return 0;
  }
  j = -j;
  k *= t / d;
  j *= t / d;
  if (k > 0 && j > 0) {
    long long tt = min(k / (m / d), j / (n / d));
    k -= tt * (m / d);
    j -= tt * (n / d);
  }
  while (k < 0 || j < 0) {
    k += m / d;
    j += n / d;
  }
  x = x + ux * (t1 + n * k);
  x = n * (mod(x / n, 2));
  y = y + uy * (t2 + m * j);
  y = m * (mod(y / m, 2));
  cout << x << ' ' << y;
}
