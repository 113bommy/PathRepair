#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
void FASTIO() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
}
long long LongestCommonSubsequnce(string a, string b, long long i,
                                  long long j) {
  if (i == a.length() || j == b.length()) {
    return 0;
  } else if (a[i] == b[j]) {
    return 1 + LongestCommonSubsequnce(a, b, i + 1, j + 1);
  } else {
    return max(LongestCommonSubsequnce(a, b, i + 1, j),
               LongestCommonSubsequnce(a, b, i, j + 1));
  }
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a * b) / gcd(a, b); }
long long sumofdigits(long long n) {
  long long out = 0;
  while (n) {
    out += (n % 10);
    n /= 10;
  }
  return out;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long modpow(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long EuclidGCD(long long a, long long b, long long *x, long long *y) {
  if (a == 0) {
    *x = 0, *y = 1;
    return b;
  }
  long long x1, y1;
  long long gcd = EuclidGCD(b % a, a, &x1, &y1);
  *x = y1 - (b / a) * x1;
  *y = x1;
  return gcd;
}
long long modInverse(long long a, long long m) {
  long long x, y;
  long long res;
  long long g = EuclidGCD(a, m, &x, &y);
  if (g != 1)
    res = -1;
  else
    res = (x % m + m) % m;
  return res;
}
long long moddiv(long long a, long long b, long long c) {
  long long res = ((modpow(a, b, MOD)) * (modInverse(c, MOD))) % MOD;
  return res;
}
bool isPerfectSquare(long long x) {
  long long s = sqrt(x);
  return (s * s == x);
}
bool isFibonacci(long long n) {
  return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
}
double my_sqrt(double n, double s = 0, double e = -1) {
  if (e == -1) e = n;
  double mid = (s + e) / 2;
  double temp = mid * mid;
  if (abs(n - temp) < 0.00001) return mid;
  if (temp > n) return my_sqrt(n, s, mid);
  return my_sqrt(n, mid, e);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b & 1) return a * power(a, b - 1);
  long long res = power(a, b / 2);
  return res * res;
}
void buildTree(long long a[], long long tree[], long long s, long long e,
               long long ind) {
  if (s == e) {
    tree[ind] = a[s];
    return;
  }
  long long m = (s + e) / 2;
  buildTree(a, tree, s, m, 2 * ind);
  buildTree(a, tree, m + 1, e, 2 * ind + 1);
  tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
  return;
}
long long queryTree(long long tree[], long long n_s, long long n_e,
                    long long q_s, long long q_e, long long ind) {
  if (n_s >= q_s && n_e <= q_e) {
    return tree[ind];
  }
  if (q_e < n_s || q_s > n_e) {
    return LONG_MIN;
  }
  long long m = (n_s + n_e) / 2;
  long long pos1 = 0, pos2 = 0;
  pos1 = queryTree(tree, n_s, m, q_s, q_e, 2 * ind);
  pos2 = queryTree(tree, m + 1, n_e, q_s, q_e, 2 * ind + 1);
  return max(pos1, pos2);
}
void updateNode(long long tree[], long long n_s, long long n_e, long long i,
                long long change, long long ind) {
  if (i < n_s || i > n_e) {
    return;
  }
  if (n_s == n_e) {
    tree[ind] = change;
    return;
  }
  long long m = (n_s + n_e) / 2;
  updateNode(tree, n_s, m, i, change, 2 * ind);
  updateNode(tree, m + 1, n_e, i, change, 2 * ind + 1);
  tree[ind] = max(tree[2 * ind], tree[2 * ind + 1]);
  return;
}
bool isPalin(string a) {
  long long s = 0;
  long long e = a.length() - 1;
  while (s <= e) {
    if (a[s] != a[e]) {
      return false;
    }
    s++;
    e--;
  }
  return true;
}
bool solve(long long t) {
  if (t == 0) return false;
  return true;
}
int32_t main() {
  FASTIO();
  long long n, m;
  cin >> n >> m;
  long long usb[n];
  for (long long i = 0; i < n; i++) cin >> usb[i];
  sort(usb, usb + n, greater<long long>());
  long long cnt = 0;
  long long res = 0;
  for (long long i = 0; i < n; i++) {
    res += usb[i];
    cnt++;
    if (res >= m) {
      break;
    }
  }
  cout << cnt << "\n";
  return 0;
}
