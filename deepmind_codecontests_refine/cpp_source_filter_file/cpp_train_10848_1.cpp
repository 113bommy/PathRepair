#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int64_t isPrime(int64_t n) {
  int64_t p = (int64_t)sqrt(n);
  for (int64_t i = (2); i <= (p); i += (1))
    if (n % i == 0) return 0;
  return 1;
}
int64_t pows(int64_t b, int64_t e) {
  if (e == 0)
    return 1;
  else if (e % 2 == 0) {
    int64_t a = pow(b, e / 2);
    return a * a;
  } else {
    int64_t a = pow(b, e / 2);
    return b * a * a;
  }
}
int64_t powm(int64_t a, int64_t b, int64_t m = 1000000007) {
  int64_t x = 1;
  a %= 1000000007;
  while (b) {
    if (b & 1) x = x * a % 1000000007;
    a = a * a % 1000000007;
    b >>= 1;
  }
  return x;
}
int64_t modInverse(int64_t a, int64_t m = 1000000007) {
  return powm(a, m - 2, m);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int64_t n, m, i, j, k, x, y, z, f, p, q, g, l, r, w, h,
      count = 0, count1 = 0, prod = 1, a, b, c, d, index, x1, x2, diff, ans = 0,
      sum = 0, sum1 = 0, sum2 = 0, flag = 0, flag1 = 0, flag2 = 0;
  string s, s1, s2, s3;
  cin >> a >> b >> c >> d;
  if (a - b > 1 || d - c > 1) {
    cout << "NO\n";
    return 0;
  }
  if (a - b == 1) {
    if (c == d && c == 0) {
      cout << "YES\n";
      while (b > 0) {
        cout << "0 ";
        a--;
        cout << "1 ";
        b--;
      }
      cout << "0 ";
    } else {
      cout << "NO\n";
    }
    return 0;
  }
  if (d - c == 1) {
    if (a == b && a == 0) {
      cout << "YES\n";
      while (d > 0) {
        cout << "3 ";
        d--;
        cout << "2 ";
        c--;
      }
      cout << "3 ";
    } else {
      cout << "NO\n";
    }
    return 0;
  }
  b = b - a;
  c = c - d;
  if (abs(b - c) > 1) {
    cout << "NO\n";
    return 0;
  } else {
    cout << "YES\n";
    if (b > c) {
      cout << "1 ";
      for (i = 0; i < a; i++) {
        cout << "0 1 ";
      }
      for (i = 0; i < c; i++) {
        cout << "2 1 ";
      }
      for (i = 0; i < d; i++) {
        cout << "2 3 ";
      }
    } else if (c > b) {
      for (i = 0; i < a; i++) {
        cout << "0 1 ";
      }
      for (i = 0; i < b; i++) {
        cout << "2 1 ";
      }
      cout << "2 ";
      for (i = 0; i < d; i++) {
        cout << "3 2 ";
      }
    } else {
      for (i = 0; i < a; i++) {
        cout << "0 1 ";
      }
      for (i = 0; i < b; i++) {
        cout << "2 1 ";
      }
      for (i = 0; i < d; i++) {
        cout << "2 3 ";
      }
    }
  }
}
