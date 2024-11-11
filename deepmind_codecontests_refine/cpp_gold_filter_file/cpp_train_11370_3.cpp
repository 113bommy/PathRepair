#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-Ofast")
#pragma GCC optimize("trapv")
long long power(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long p = power(x, y / 2);
  p = (p * p);
  return (y % 2 == 0) ? p : (x * p);
}
long long powm(long long x, long long y, long long m) {
  long long ans = 1, r = 1;
  x %= m;
  while (r > 0 && r <= y) {
    if (r & y) {
      ans *= x;
      ans %= m;
    }
    r <<= 1;
    x *= x;
    x %= m;
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
long long lcm(long long a, long long b) {
  long long lar = max(a, b);
  long long small = min(a, b);
  for (long long i = lar;; i += lar) {
    if (i % small == 0) {
      return i;
    }
  }
}
bool sortbysec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.second < b.second);
}
bool sortbydec(const pair<long long, long long> &a,
               const pair<long long, long long> &b) {
  return (a.first > b.first);
}
void dex(int a) {
  if (a == 1) {
    cout << "YES";
  }
  if (a == 2) {
    cout << "NO";
  }
  if (a == 3) {
    cout << "Yes";
  }
  if (a == 4) {
    cout << "No";
  }
}
void line(long long x) {
  for (long long i = 1; i <= x; i++) {
    cout << "-";
  }
  cout << '\n';
}
bool overflow(long double a, long double b) { return a * b > 1e18 + 10; }
const long long N = (long long)(1e5 + 1);
const long long MOD = (long long)(1e9 + 7);
const long long INF = (long long)(2e18);
void solve(long long tc) {
  long long n, m;
  cin >> n >> m;
  char a[n + 1][m + 1];
  long long b[n + 1], c[m + 1];
  memset(b, 0, sizeof(b));
  memset(c, 0, sizeof(c));
  long long f0 = 0, f1 = 0, f2 = 0, f3 = 0, f4 = 0;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'P') {
        f0 = 1;
      }
      b[i] += (a[i][j] == 'A');
    }
  }
  for (long long i = 1; i <= m; i++) {
    for (long long j = 1; j <= n; j++) {
      c[i] += (a[j][i] == 'A');
    }
  }
  for (long long i = 1; i <= n; i++) {
    if (i == 1 || i == n) {
      if (b[i] == m) {
        f1 = 1;
      }
      if (b[i] > 0) {
        f3 = 1;
      }
    } else {
      if (b[i] == m) {
        f2 = 1;
      }
    }
    if (b[i] > 0) {
      f4 = 1;
    }
  }
  for (long long i = 1; i <= m; i++) {
    if (i == 1 || i == m) {
      if (c[i] == n) {
        f1 = 1;
      }
      if (c[i] > 0) {
        f3 = 1;
      }
    } else {
      if (c[i] == n) {
        f2 = 1;
      }
    }
    if (c[i] > 0) {
      f4 = 1;
    }
  }
  if (a[1][1] == 'A' || a[n][1] == 'A' || a[1][m] == 'A' || a[n][m] == 'A') {
    f2 = 1;
  }
  if (f0 == 0) {
    cout << 0 << '\n';
  } else if (f1) {
    cout << 1 << '\n';
  } else if (f2) {
    cout << 2 << '\n';
  } else if (f3) {
    cout << 3 << '\n';
  } else if (f4) {
    cout << 4 << '\n';
  } else {
    cout << "MORTAL" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long cnt = 1;
  long long t;
  cin >> t;
  while (t--) {
    for (auto blockTime = make_pair(chrono::high_resolution_clock::now(), true);
         blockTime.second;
         fprintf(stderr, "%s: %lld ms\n", "solve",
                 chrono::duration_cast<chrono::milliseconds>(
                     chrono::high_resolution_clock::now() - blockTime.first)
                     .count()),
              fflush(stderr), blockTime.second = false) {
      solve(cnt);
    }
    cnt++;
  }
  return 0;
}
