#include <bits/stdc++.h>
using namespace std;
const long long int ZERO = 0LL;
const long long int ONE = 1LL;
const int N = 4e5;
const int K = 20;
const long long int OO = 2e9;
const double PI = acos(-1);
const long long int MD = 1e9 + 7;
template <typename T>
class FT {
 private:
  int n;
  vector<T> fen;

 public:
  FT() { this->n = 0; }
  FT(int n) {
    this->n = n + 1;
    this->fen.resize(this->n, 0);
  }
  void reset(int n) {
    this->n = n + 1;
    this->fen.clear();
    this->fen.resize(this->n, 0);
  }
  void add(int idx, T val) {
    for (; idx <= n; idx += (idx & -idx)) {
      fen[idx] = fen[idx] + val;
    }
  }
  T get(int idx) {
    T sum = 0;
    for (; idx > 0; idx -= (idx & -idx)) {
      sum = sum + fen[idx];
    }
    return sum;
  }
  T get(int l, int r) { return get(r) - get(l - 1); }
};
class Hash {
 private:
  int p;
  int m;
  int n;
  vector<long long int> p_pow;
  vector<long long int> h;

 public:
  Hash(int p, int m, int n, string &s, char min_char) {
    this->n = n;
    this->p = p;
    this->m = m;
    this->p_pow.resize(n);
    this->h.resize(n + 1, 0);
    p_pow[0] = 1;
    for (int i = 1; i < n; i++) {
      p_pow[i] = (p_pow[i - 1] * p) % m;
    }
    for (int i = 0; i < n; i++) {
      h[i + 1] = (h[i] + (s[i] - min_char + 1) * p_pow[i]) % m;
    }
  }
  long long int get() { return h[n]; }
  long long int get(int l, int r) {
    long long int hash = (h[r + 1] + m - h[l]) % m;
    hash = (hash * p_pow[n - r - 1]) % m;
    return hash;
  }
};
template <typename T>
class GCD {
 public:
  static T get(T a, T b, T &x, T &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    T x1, y1;
    T d = get(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
  }
  static T get(T a, T b) {
    if (b == 0) {
      return a;
    }
    return get(b, a % b);
  }
  virtual ~GCD() = 0;
};
template <typename T>
class point2d {
 private:
  T x, y;

 public:
  point2d() {}
  point2d(T x, T y) {
    this->x = x;
    this->y = y;
  }
  point2d add(point2d p) {
    point2d newPoint(this->x + p.x, this->y + p.y);
    return newPoint;
  }
  point2d sub(point2d p) {
    point2d newPoint(this->x - p.x, this->y - p.y);
    return newPoint;
  }
  point2d mult(point2d p) {
    point2d newPoint(this->x * p.x, this->y * p.y);
    return newPoint;
  }
  T dot(point2d p) { return this->x * p.x + this->y * p.y; }
  T cross(point2d p) { return this->x * p.y - this->y * p.x; }
  T len() { return sqrt(this->x * this->x + this->y * this->y); }
  long double angle(point2d p) {
    return acos(dot(p) * 1.0 / len() / p.len()) * (180.0 / PI);
  }
  long double dis(point2d p, bool with_sqrt) {
    point2d d = sub(p);
    if (with_sqrt)
      return sqrt(d.x * d.x + d.y * d.y);
    else
      return d.x * d.x + d.y * d.y;
  }
};
template <typename T>
void input(vector<T> &v) {
  for (auto &u : v) cin >> u;
}
template <typename T>
void print(vector<T> &v) {
  for (auto u : v) cout << u << " ";
}
long long int Pow(long long int val, long long int freq) {
  long long int ans = 1;
  for (int i = 0; i < freq; i++) ans *= val;
  return ans;
}
int t = 1;
int n, dp[10000001][2];
int add(int a, int b) { return (a + b) % MD; }
int mult(int a, int b) { return (a * b) % MD; }
int main() {
  while (t--) {
    scanf("%d", &n);
    dp[n][1] = 1;
    for (int i = n - 1; i >= 0; i--) {
      dp[i][1] = add(dp[i][1], mult(dp[i + 1][0], 3));
      dp[i][0] = add(dp[i][0], mult(dp[i + 1][0], 2));
      dp[i][0] = add(dp[i][0], dp[i + 1][1]);
    }
    printf("%d", dp[0][1]);
  }
  return 0;
}
