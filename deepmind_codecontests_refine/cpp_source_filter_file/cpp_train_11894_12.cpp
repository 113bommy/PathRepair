#include <bits/stdc++.h>
long long exp(long long x, long long y, long long p) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % p) % p;
    x = (x * x) % p;
    y /= 2;
  }
  return res;
}
long long expo(long long x, long long y) {
  long long res = 1;
  while (y) {
    if (y % 2) res = (res * x % ((long long)1e8)) % ((long long)1e8);
    x = (x * x) % ((long long)1e8);
    y /= 2;
  }
  return res;
}
long long add(long long a, long long b) {
  return (a % ((long long)1e8) + b % ((long long)1e8) + ((long long)1e8)) %
         ((long long)1e8);
}
long long sub(long long a, long long b) {
  return (a % ((long long)1e8) - b % ((long long)1e8) + ((long long)1e8)) %
         ((long long)1e8);
}
long long mul(long long a, long long b) {
  return ((a % ((long long)1e8)) * (b % ((long long)1e8)) + ((long long)1e8)) %
         ((long long)1e8);
}
long long inv(long long x) { return expo(x, ((long long)1e8) - 2); }
using namespace std;
void p5(long long l) {
  cout << l << " ";
  cout << l + 2 << " ";
  cout << l + 4 << " ";
  cout << l + 1 << " ";
  cout << l + 3 << " ";
}
void p4(long long l) {
  cout << l + 1 << " ";
  cout << l + 3 << " ";
  cout << l << " ";
  cout << l + 2 << " ";
}
void p6(long long l) {
  cout << l << " ";
  cout << l + 2 << " ";
  cout << l + 4 << " ";
  cout << l + 1 << " ";
  cout << l + 5 << " ";
  cout << l + 3 << " ";
}
void p7(long long l) {
  cout << l << " ";
  cout << l + 3 << " ";
  cout << l + 6 << " ";
  cout << l + 4 << " ";
  cout << l + 1 << " ";
  cout << l + 5 << " ";
  cout << l + 2 << " ";
}
void solve() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    cout << setprecision(10);
    long long n, m, i, j, k, x, y, f = 0;
    cin >> n;
    if (n < 4) {
      cout << -1 << "\n";
      continue;
    }
    long long c = 1;
    while (n > 9) {
      p5(c);
      c = c + 5;
      n = n - 5;
    }
    if (n == 8) {
      p4(c);
      c = c + 4;
      p4(c);
      n = 0;
    }
    if (n == 7) {
      p7(c);
      n = 0;
    }
    if (n == 6) {
      p6(c);
      n = 0;
    }
    if (n == 5) {
      p5(c);
      n = 0;
    }
    if (n == 4) {
      p4(c);
      n = 0;
    }
    cout << "\n";
  }
}
signed main() {
  { solve(); }
  return 0;
}
