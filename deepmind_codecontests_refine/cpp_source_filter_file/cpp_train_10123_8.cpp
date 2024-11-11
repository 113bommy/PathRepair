#include <bits/stdc++.h>
using namespace std;
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << ' ' << H;
  dbg_out(T...);
}
pair<int, int> operator*(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator%(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first % x.first, p.second % x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<int, int> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator*(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first * x.first, p.second * x.second);
  return np;
}
pair<long long, long long> operator+(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<long long, long long> operator-(const pair<long long, long long> &p,
                                     const pair<long long, long long> &x) {
  pair<long long, long long> np =
      make_pair(p.first - x.first, p.second - x.second);
  return np;
}
pair<int, int> operator+(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first + x.first, p.second + x.second);
  return np;
}
pair<int, int> operator-(const pair<int, int> &p, const pair<int, int> &x) {
  pair<int, int> np = make_pair(p.first - x.first, p.second - x.second);
  return np;
}
vector<int> prime;
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
bool sortbysecdesc(const pair<int, int> &a, const pair<int, int> &b) {
  return a.second > b.second;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
long long powerm(long long a, long long k) {
  if (!k) {
    return 1;
  }
  long long b = powerm(a, k / 2);
  b = b * b % 998244353;
  if (k % 2) {
    return a * b % 998244353;
  } else {
    return b;
  }
}
long long power(long long a, long long b) {
  if (b == 1) return a;
  if (b == 0) return 1;
  long long m1 = power(a, b / 2);
  if (b % 2) return m1 * m1 * a;
  return m1 * m1;
}
void PFactor(int x) {
  prime.clear();
  for (int i = 2; i <= x / i; i++)
    if (x % i == 0) {
      while (x % i == 0) x /= i, prime.push_back(i);
    }
  if (x > 1) prime.push_back(x);
}
bool isprime(long long a) {
  if (a <= 1) return false;
  if (a == 2 || a == 3) return true;
  if (a % 2 == 0 || a % 3 == 0) return false;
  for (long long i = 5; i * i <= a; i = i + 6) {
    if (a % i == 0 || a % (i + 2) == 0) return false;
  }
  return true;
}
const int N = 2e6 + 20;
int n = 0, m = 0, k = 0;
int a = 0, b = 0, c = 0;
string str;
int g[1001][1001];
int main() {
  cin >> n;
  if (n == 1 || n == 2) {
    cout << -1;
    return 0;
  }
  if (n == 4) {
    cout << "4 3 6 12\n7 5 9 15\n14 1 11 10\n13 8 16 2";
    return 0;
  }
  int x = n * n - n + 1;
  g[n][1] = x;
  for (int j = 2; j <= n; j++) g[n - 1][j] = ++x;
  x = 0;
  for (int i = 1; i <= n - 1; i++) g[i][1] = ++x;
  for (int j = 2; j <= n; j++) g[n][j] = ++x;
  for (int i = n - 2; i >= 1; i--) g[i][n] = ++x;
  for (int i = 1; i <= n - 2; i++) {
    if (i % 2)
      for (int j = n - 1; j >= 2; j--) g[i][j] = ++x;
    else
      for (int j = 2; j <= n - 1; j++) g[i][j] = ++x;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%4d", g[i][j]);
    }
    cout << endl;
  }
}
