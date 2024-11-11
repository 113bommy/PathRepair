#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int maxn = 1e7 + 10;
const int INF = 1000000000;
const long long mod = 1e9 + 7;
struct matrix {
  long long matrixRemainder = mod - 1;
  int row, col;
  std::vector<std::vector<long long>> num;
  matrix(int row, int col, int defaultValue = 0) {
    this->num = std::vector<std::vector<long long>>(
        row, std::vector<long long>(col, defaultValue));
    this->row = row, this->col = col;
  }
  matrix(std::vector<std::vector<long long>> num) {
    this->num = num;
    this->row = this->num.size();
    this->col = this->num[0].size();
  }
  matrix operator*(matrix &another) {
    if (this->col != another.row) {
      printf("Wrong size: %d*%d X %d*%d\n", this->row, this->col, another.row,
             another.col);
      throw "Wrong size";
    }
    matrix newone(this->row, another.col);
    for (int r = 0; r < newone.row; r++)
      for (int c = 0; c < newone.col; c++) {
        for (int k = 0; k < this->col; k++) {
          newone.num[r][c] += this->num[r][k] * another.num[k][c];
          newone.num[r][c] %= matrixRemainder;
        }
      }
    return newone;
  }
  matrix operator^(long long x) {
    if (x == 0) {
      printf("Not implemented yet.\n");
      throw "Not implemented";
    } else if (x == 1)
      return *this;
    else {
      matrix halfpower = (*this) ^ (x / 2);
      if (x % 2 == 0)
        return halfpower * halfpower;
      else
        return halfpower * halfpower * (*this);
    }
  }
  matrix operator+(matrix &ano) {
    matrix tmp = *this;
    for (int i = (0); i < (row); ++i)
      for (int j = (0); j < (col); ++j) {
        tmp.num[i][j] += ano.num[i][j], tmp.num[i][j] %= matrixRemainder;
      }
    return tmp;
  }
  matrix operator-(matrix &ano) {
    matrix tmp = *this;
    for (int i = (0); i < (row); ++i)
      for (int j = (0); j < (col); ++j) {
        tmp.num[i][j] -= ano.num[i][j],
            tmp.num[i][j] = (tmp.num[i][j] + matrixRemainder) % matrixRemainder;
      }
    return tmp;
  }
};
bool vis[maxn];
vector<int> prime;
void sieve(int n) {
  int m = sqrt(n + 0.5);
  memset(vis, 0, sizeof(vis));
  for (int i = 2; i <= m; ++i) {
    if (!vis[i])
      for (long long j = (long long)i * i; j <= n; j += i) {
        vis[j] = 1;
      }
  }
}
void gen_prime(int n) {
  sieve(n);
  prime.clear();
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) prime.push_back(i);
  }
}
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
void gcd(long long a, long long b, long long &d, long long &x, long long &y) {
  if (!b) {
    d = a;
    x = 1;
    y = 0;
  } else {
    gcd(b, a % b, d, y, x);
    y -= x * (a / b);
  }
}
long long mul_mod(long long a, long long b, long long mod) {
  return a * b % mod;
}
long long pow_mod(long long a, long long p, long long mod) {
  if (!p) return 1 % mod;
  long long ans = pow_mod(a, p >> 1, mod);
  ans = ans * ans % mod;
  if (p % 2) ans = ans * a % mod;
  return ans;
}
int euler_phi(int n) {
  int m = sqrt(n + 0.5);
  int ans = n;
  for (int i = 2; i <= m; ++i) {
    if (ans % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) ans = ans / n * (n - 1);
}
int phi[maxn];
void phi_table(int n) {
  for (int i = 2; i <= n; ++i) phi[i] = 0;
  phi[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!phi[i]) {
      for (int j = i; j <= n; j += i) {
        if (!phi[j]) phi[j] = j;
        phi[j] = phi[j] / i * (i - 1);
      }
    }
  }
}
long long inv(long long a, long long n) {
  long long d, x, y;
  gcd(a, n, d, x, y);
  return d == 1 ? (x + n) % n : -1;
}
long long china(int n, int *a, int *m) {
  long long M = 1, d, y, x = 0;
  for (int i = 0; i < n; ++i) M *= m[i];
  for (int i = 0; i < n; ++i) {
    long long w = M / m[i];
    gcd(m[i], w, d, d, y);
    x = (x + y * w * a[i]) % M;
  }
  return (x + M) % M;
}
int log_mod(int a, int b, int n) {
  int m = sqrt(n + 0.5);
  int v = inv(pow_mod(a, m, n), n);
  map<int, int> x;
  x[1] = 0;
  int e = 1;
  for (int i = 1; i < m; ++i) {
    e = mul_mod(e, a, n);
    if (!x.count(e)) x[e] = i;
  }
  for (int i = 0; i < m; ++i) {
    if (x.count(b)) return i * m + x[b];
    b = mul_mod(b, v, n);
  }
  return -1;
}
vector<pair<long long, int>> decomposition(long long x) {
  vector<pair<long long, int>> ans;
  long long m = sqrt(x + 0.5);
  for (int t = (0); t < (prime.size()); ++t) {
    if (prime[t] > m) break;
    if (x % prime[t] == 0) {
      int cnt = 0;
      while (x % prime[t] == 0) {
        x /= prime[t];
        ++cnt;
      }
      ans.push_back(make_pair(prime[t], cnt));
    }
    if (x == 1) break;
  }
  if (x > 1) {
    ans.push_back(make_pair(x, 1));
  }
  return ans;
}
long long n, f1, f2, f3, c;
matrix ma(3, 3, 0);
int main() {
  cin >> n >> f1 >> f2 >> f3 >> c;
  ma.num[0][1] = ma.num[1][2] = ma.num[2][0] = ma.num[2][1] = ma.num[2][2] = 1;
  matrix tmp = ma ^ (n - 3);
  long long p = tmp.num[2][0], q = tmp.num[2][1], r = tmp.num[2][2];
  long long invc = inv(pow_mod(c, n, mod), mod);
  long long tp = pow_mod(c, p + q * 2 + r * 3, mod);
  tp = mul_mod(tp, invc, mod);
  long long tp1 = pow_mod(f1, p, mod), tp2 = pow_mod(f2, q, mod),
            tp3 = pow_mod(f3, r, mod);
  tp1 = mul_mod(tp1, tp2, mod);
  tp1 = mul_mod(tp1, tp3, mod);
  long long ans = mul_mod(tp, tp1, mod);
  cout << ans;
}
