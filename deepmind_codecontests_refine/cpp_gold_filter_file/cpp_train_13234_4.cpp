#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const long long INFLL = 1e18 + 1;
const int MAX = 200001;
const long long MOD = 1000000007;
const int SZ = 300100;
const double PI = 3.14159265358979323846264338327;
long long inq(long long k, long long q, long long mod) {
  if (q == 0) return 1;
  long long l = inq(k, q / 2, mod);
  if (q % 2 == 0)
    return l * l % mod;
  else
    return l * l % mod * k % mod;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long cubr(long long a) {
  long long l = -1, r = 1e6 + 2;
  while (l < r - 1) {
    long long mid = (l + r) / 2;
    if (mid * mid * mid > a)
      r = mid;
    else
      l = mid;
  }
  return l;
}
long long max(long long a, long long b) {
  if (a > b) return a;
  return b;
}
long long min(long long a, long long b) { return -1 * max(-a, -b); }
long long possible(long long q) {
  if (q == INF) return -1;
  return q;
}
bool correct(int x, int xx) {
  if (x < 0) return 0;
  if (x >= xx) return 0;
  return 1;
}
long long dsumm(long long x, long long k) {
  long long y = 1;
  long long z = 0;
  for (int i = 0; y < 1e18; i++) {
    z += x / y % k;
    y *= k;
  }
  return z;
}
long long dcount(long long x) {
  long long y = 1;
  long long z = 0;
  int c[100];
  for (int i = 0; i < 10; i++) c[i] = 0;
  for (int i = 0; x > 0; i++) {
    if (c[x / y % 10] == 0) z++;
    c[x / y % 10] = 1;
    x /= 10;
  }
  return z;
}
long long lg10(long long x) {
  if (10000 <= x && x < 100000) return 5;
  if (x == 0) return 0;
  return lg10(x / 10) + 1;
}
long long g(long long x, long long mod) {
  if (x == 0) return 0;
  return x / mod + g(x / mod, mod);
}
bool is_digit(char c) { return ('0' <= c && c <= '9'); }
long long n, m;
string s[500000];
vector<int> t[500000];
vector<char> fant[500000];
long long ans;
vector<char> answ[500000];
bool check_invertation_rows(int i) {
  int now = 0;
  for (int j = 0; j < m; j++) {
    if (t[i][j] != 5) {
      now += (fant[i][j] != s[i][j]);
    }
  }
  int will = 0;
  for (int j = 0; j < m; j++) {
    if (j % 2 == 0 && t[i][j] != 5) {
      will += (fant[i][1] != s[i][j]);
    }
    if (j % 2 == 1 && t[i][j] != 5) {
      will += (fant[i][0] != s[i][j]);
    }
  }
  if (will < now) {
    for (int j = 0; j < m; j += 2) {
      swap(fant[i][j], fant[i][j + 1]);
    }
    return 1;
  }
  return 0;
}
bool check_invertation_coll(int j) {
  int now = 0;
  for (int i = 0; i < n; i++) {
    if (t[i][j] != 5) {
      now += (fant[i][j] != s[i][j]);
    }
  }
  int will = 0;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0 && t[i][j] != 5) {
      will += (fant[1][j] != s[i][j]);
    }
    if (i % 2 == 1 && t[i][j] != 5) {
      will += (fant[0][j] != s[i][j]);
    }
  }
  if (will < now) {
    for (int i = 0; i < n; i += 2) {
      swap(fant[i][j], fant[i + 1][j]);
    }
    return 1;
  }
  return 0;
}
void checker(vector<char> c) {
  for (int i = 0; i < n; i++) {
    fant[i].resize(m, 0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i % 2;
      int y = j % 2;
      if (x == 0 && y == 0) {
        fant[i][j] = c[0];
      }
      if (x == 0 && y == 1) {
        fant[i][j] = c[1];
      }
      if (x == 1 && y == 0) {
        fant[i][j] = c[2];
      }
      if (x == 1 && y == 1) {
        fant[i][j] = c[3];
      }
    }
  }
  for (int i = 2; i < n; i++) {
    check_invertation_rows(i);
  }
  int ext = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] != 5) {
        ext += (fant[i][j] != s[i][j]);
      }
    }
  }
  if (ext < ans) {
    ans = ext;
    for (int i = 0; i < n; i++) {
      answ[i] = fant[i];
    }
  }
  for (int i = 0; i < n; i++) {
    fant[i].resize(m, 0);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x = i % 2;
      int y = j % 2;
      if (x == 0 && y == 0) {
        fant[i][j] = c[0];
      }
      if (x == 0 && y == 1) {
        fant[i][j] = c[1];
      }
      if (x == 1 && y == 0) {
        fant[i][j] = c[2];
      }
      if (x == 1 && y == 1) {
        fant[i][j] = c[3];
      }
    }
  }
  for (int i = 2; i < m; i++) {
    check_invertation_coll(i);
  }
  ext = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] != 5) {
        ext += (fant[i][j] != s[i][j]);
      }
    }
  }
  if (ext < ans) {
    ans = ext;
    for (int i = 0; i < n; i++) {
      answ[i] = fant[i];
    }
  }
}
signed main() {
  ans = INF;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    int e = m % 2;
    if (e) {
      s[i] = s[i] + 'Q';
    }
    t[i].resize(m + e);
    for (int j = 0; j < m + e; j++) {
      if (s[i][j] == 'A') {
        t[i][j] = 1;
      }
      if (s[i][j] == 'C') {
        t[i][j] = 2;
      }
      if (s[i][j] == 'G') {
        t[i][j] = 3;
      }
      if (s[i][j] == 'T') {
        t[i][j] = 4;
      }
      if (s[i][j] == 'Q') {
        t[i][j] = 5;
      }
    }
  }
  if (m % 2) {
    m++;
  }
  if (n % 2) {
    t[n].resize(m);
    for (int i = 0; i < m; i++) {
      t[n][i] = 5;
    }
    n++;
  }
  vector<char> perm;
  perm.push_back('A');
  perm.push_back('C');
  perm.push_back('G');
  perm.push_back('T');
  for (int i = 0; i < 24; i++) {
    checker(perm);
    next_permutation((perm).begin(), (perm).end());
  }
  cerr << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (t[i][j] != 5) {
        cout << answ[i][j];
      }
    }
    cout << endl;
  }
}
