#include <bits/stdc++.h>
using namespace std;
template <typename T>
T modpow(T base, T exp, T modulus) {
  base %= modulus;
  T result = 1;
  while (exp > 0) {
    if (exp & 1) result = (result * base) % modulus;
    base = (base * base) % modulus;
    exp >>= 1;
  }
  return result;
}
bool sortbysec(const pair<pair<long long, long long>, long long> &a,
               const pair<pair<long long, long long>, long long> &b) {
  if (a.first.first == b.first.first && a.first.second == b.first.second)
    return a.second > b.second;
  else if (a.first.second == b.first.second)
    return a.first.first > b.first.first;
  return a.first.second < b.first.second;
}
struct cmp {
  bool operator()(const pair<int, int> &a, const pair<int, int> &b) const {
    int lena = a.second - a.first + 1;
    int lenb = b.second - b.first + 1;
    if (lena == lenb) return a.first < b.first;
    return lena > lenb;
  }
};
struct c_h {
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    x ^= FIXED_RANDOM;
    return x ^ (x >> 16);
  }
};
long long calcpow(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = calcpow(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else {
    if (y > 0)
      return x * temp * temp;
    else
      return (temp * temp) / x;
  }
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long egcd(long long a, long long b, long long &x, long long &y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1;
  long long y1;
  long long g = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return g;
}
bool isprime(long long a) {
  bool flag = 1;
  for (long long i = 2; i * i <= a; i++) {
    if (a % i == 0) {
      flag = 0;
      break;
    }
  }
  return flag;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long a, b;
  cin >> a >> b;
  long long g = gcd(a, b);
  vector<long long> vec;
  vec.push_back(1);
  vec.push_back(g);
  for (long long i = 2; i * i <= g; i++) {
    if (g % i == 0) {
      vec.push_back(i);
      if (i != g / i) vec.push_back(g / i);
    }
  }
  long long n;
  cin >> n;
  sort(vec.begin(), vec.end());
  for (long long i = 0; i < n; i++) {
    long long l, r;
    cin >> l >> r;
    auto x = lower_bound(vec.begin(), vec.end(), r + 1);
    x--;
    if (x == vec.begin() || (*x) < l)
      cout << "-1 \n";
    else
      cout << (*x) << endl;
  }
}
