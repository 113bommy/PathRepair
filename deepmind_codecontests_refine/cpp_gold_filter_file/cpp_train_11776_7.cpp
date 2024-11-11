#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  return b == 0 ? a : gcd(b, a % b);
}
template <typename T>
void read(T &res) {
  bool flag = false;
  char ch;
  while (!isdigit(ch = getchar())) (ch == '-') && (flag = true);
  for (res = ch - 48; isdigit(ch = getchar());
       res = (res << 1) + (res << 3) + ch - 48)
    ;
  flag && (res = -res);
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long qp(long long a, long long b, long long mod) {
  long long ans = 1;
  if (b == 0) {
    return ans % mod;
  }
  while (b) {
    if (b % 2 == 1) {
      b--;
      ans = ans * a % mod;
    }
    a = a * a % mod;
    b = b / 2;
  }
  return ans % mod;
}
long long qpn(long long a, long long b, long long p) {
  long long ans = 1;
  a %= p;
  while (b) {
    if (b & 1) {
      ans = (ans * a) % p;
      --b;
    }
    a = (a * a) % p;
    b >>= 1;
  }
  return ans % p;
}
struct pe {
  long long t;
  long long s;
} a[222222];
long long dp[100009];
long long sum[100009];
vector<pair<long long, long long>> pos_1;
vector<long long> end_1;
signed main() {
  long long n, k, q;
  read(n);
  read(k);
  read(q);
  long long f = 0;
  if (n % 2 == 1) {
    n--;
    k--;
    if (k >= 0) {
      f = 1;
    }
  }
  while (q--) {
    long long pos;
    read(pos);
    long long oushu = n / 2;
    if (pos > n) {
      if (f) {
        printf("X");
        continue;
      } else {
        printf(".");
        continue;
      }
    } else if (k <= oushu) {
      if (pos % 2 == 1) {
        printf(".");
        continue;
      } else if (pos / 2 > oushu - k) {
        printf("X");
        continue;
      } else {
        printf(".");
        continue;
      }
    } else {
      if (pos % 2 == 0) {
        printf("X");
        continue;
      } else if (pos / 2 + 1 > n - k) {
        printf("X");
        continue;
      }
      printf(".");
    }
  }
}
