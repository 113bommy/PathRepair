#include <bits/stdc++.h>
using namespace std;
long long p;
vector<vector<long long> > zero(int n) {
  return vector<vector<long long> >(n, vector<long long>(n, 0));
}
vector<vector<long long> > unit(int n) {
  vector<vector<long long> > a = zero(n);
  for (int i = 0; i < n; ++i) {
    a[i][i] = 1;
  }
  return a;
}
int MOD;
vector<vector<long long> > operator*(vector<vector<long long> > a,
                                     vector<vector<long long> > b) {
  int n = a.size();
  vector<vector<long long> > c = zero(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        (c[i][j] += a[i][k] * b[k][j]) %= MOD;
      }
    }
  }
  return c;
}
vector<long long> operator*(vector<long long> a, vector<vector<long long> > m) {
  int n = a.size();
  vector<long long> c(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      (c[j] += m[i][j] * a[i]) %= MOD;
    }
  }
  return c;
}
vector<vector<long long> > matPow(vector<vector<long long> > a, long long e) {
  if (!e) return unit(a.size());
  return (e & 1) ? matPow(a, e - 1) * a : matPow(a * a, e >> 1);
}
long long myPow(long long a, long long e, long long mod) {
  if (!e) return 1LL;
  return (e & 1) ? myPow(a, e - 1, mod) * a % mod
                 : myPow(a * a % mod, e >> 1, mod);
}
long long calc(long long sum, long long min, long long max, long long x) {
  long long A = (myPow(3, x, p * 2) + 1) / 2;
  long long ret = sum * (2 * A) - min * A - max * A - (sum - min - max);
  ret %= p;
  if (ret < 0) ret += p;
  return ret;
}
int main() {
  int n;
  long long x, y;
  cin >> n >> x >> y >> p;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  if (n == 1) {
    cout << a[0] % p << endl;
    return 0;
  }
  long long sum = accumulate(a.begin(), a.end(), 0LL);
  long long afterSum = calc(sum, a.front(), a.back(), x);
  long long min = a.front();
  long long max;
  MOD = p;
  {
    vector<vector<long long> > m = zero(2);
    m[0][1] = m[1][1] = 1;
    m[1][0] = 1;
    vector<long long> v;
    v.push_back(a[n - 2]);
    v.push_back(a[n - 1]);
    v = v * matPow(m, x);
    max = v[1];
  }
  cout << calc(afterSum, min, max, y) << endl;
  return 0;
}
