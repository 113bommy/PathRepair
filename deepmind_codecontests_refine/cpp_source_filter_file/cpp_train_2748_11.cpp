#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long z = 1000000000;
const long long N = 1e5 + 1;
template <typename T1, typename T2>
istream& operator>>(istream& in, pair<T1, T2>& a) {
  in >> a.first >> a.second;
  return in;
}
template <typename T1, typename T2>
ostream& operator<<(ostream& out, pair<T1, T2> a) {
  out << a.first << " " << a.second;
  return out;
}
template <typename T, typename T1>
T amax(T& a, T1 b) {
  if (b > a) a = b;
  return a;
}
template <typename T, typename T1>
T amin(T& a, T1 b) {
  if (b < a) a = b;
  return a;
}
const long long INF = 1e18;
long long sumofdigit(long long a) {
  long long ans = 0;
  while (a) {
    ans += a % 10;
    a = a / 10;
  }
  return ans;
}
vector<long long> fib(100005);
void fibo() {
  fib[0] = 1;
  fib[1] = 1;
  fib[2] = 2;
  for (int i = 3; i <= 10000; i++)
    fib[i] = (fib[i - 1] % mod + fib[i - 2] % mod) % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(n, 0)),
      b(n, vector<long long>(n, 0));
  for (long long i = 0; i < m; i++) {
    long long j, k;
    cin >> j >> k;
    a[j - 1][k - 1] = 1;
  }
  vector<long long> col(n), row(n);
  for (long long i = 1; i < n - 1; i++) {
    if (a[i][0] == 1) {
      row[i] = 1;
    }
    if (a[i][n - 1] == 1) {
      row[i] = 1;
    }
  }
  for (long long i = 1; i < n - 1; i++) {
    if (a[0][i] == 1) {
      col[i] = 1;
    }
    if (a[n - 1][i] == 1) {
      col[i] = 1;
    }
  }
  for (long long i = 1; i < n - 1; i++) {
    for (long long j = 1; j < n - 1; j++) {
      if (a[i][j] == 1) {
        a[i][0] = 1;
        a[i][n - 1] = 1;
        a[0][j] = 1;
        a[n - 1][j] = 1;
      }
    }
  }
  for (long long i = 1; i < n - 1; i++) {
    if (col[i] == 1) {
      a[0][i] = 1;
      a[n - 1][i] = 1;
    }
    if (row[i] == 1) {
      a[i][0] = 1;
      a[i][n - 1] = 1;
    }
  }
  long long cnt = 0;
  for (long long i = 1; i < n - 1; i++) {
    if (a[0][i] == 0 && a[n - 1][i] == 0) {
      cnt++;
    }
    if (a[0][i] == 0 && a[n - 1][i] == 0) {
      cnt++;
    }
  }
  if (n % 2 == 1) {
    if (a[0][n / 2] == 0 && a[n - 1][n / 2] == 0 && a[n / 2][0] == 0 &&
        a[n / 2][n - 1] == 0)
      cnt--;
  }
  cout << cnt;
}
