#include <bits/stdc++.h>
using namespace std;
long long gcd(long long x, long long y) {
  if (x == 0) return y;
  return gcd(y % x, x);
}
long long powmod(long long x, long long y, long long m) {
  if (y == 0) return 1;
  long long p = powmod(x, y / 2, m) % m;
  p = (p * p) % m;
  return (y % 2 == 0) ? p : (x * p) % m;
}
long long mul_inv(long long a, long long b) {
  long long b0 = b, t, q;
  long long x0 = 0ll, x1 = 1ll;
  if (b == 1ll) return 1ll;
  while (a > 1ll) {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }
  if (x1 < 0ll) x1 += b0;
  return x1;
}
bool fa(vector<long long> &x, vector<long long> &y) { return x[0] < y[0]; }
bool fa1(vector<long long> &x, vector<long long> &y) { return x[1] < y[1]; }
bool f1(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.second > y.second;
}
bool f2(pair<long long, long long> &x, pair<long long, long long> &y) {
  return x.first > y.first;
}
bool f3(long long &x, long long &y) { return x > y; }
const long long maxn = 2e5 + 2;
vector<vector<long long> > id(long long n) {
  vector<vector<long long> > temp;
  temp.resize(n);
  for (int i = 0; i < n; i++) {
    temp[i].resize(n);
    temp[i][i] = 1;
  }
  return temp;
}
vector<vector<long long> > mul(vector<vector<long long> > &x,
                               vector<vector<long long> > &y) {
  long long a = x.size(), b = x[0].size(), c = y.size(), d = y[0].size();
  vector<vector<long long> > ans;
  if (b != c) {
    cout << "invalid\n";
    exit(0);
  }
  ans.resize(a);
  for (int i = 0; i < a; i++) {
    ans[i].resize(d);
    for (int k = 0; k < b; k++) {
      for (int t = 0; t < d; t++) {
        ans[i][t] += x[i][k] * y[k][t];
        ans[i][t] %= 1000000007;
      }
    }
  }
  return ans;
}
vector<vector<long long> > powmat(vector<vector<long long> > x, long long n,
                                  long long m) {
  vector<vector<long long> > ans = id(x.size());
  while (n > 0) {
    if (n & 1ll) {
      ans = mul(ans, x);
    }
    x = mul(x, x);
    n >>= 1ll;
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n;
  cin >> n;
  long long b[n];
  long long c[n + 1];
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    c[b[i]] = i;
  }
  vector<array<long long, 2> > d(n);
  vector<long long> temp;
  for (int i = 0; i < n; i++) {
    while (temp.size() > 0 && b[temp.back()] < b[i]) {
      temp.pop_back();
    }
    if (temp.size() == 0) {
      d[i][0] = 0;
    } else {
      d[i][0] = temp.back() + 1;
    }
    temp.push_back(i);
  }
  temp.clear();
  for (long long i = n - 1; i >= 0; i--) {
    while (temp.size() > 0 && b[temp.back()] < b[i]) {
      temp.pop_back();
    }
    if (temp.size() == 0) {
      d[i][1] = n - 1;
    } else {
      d[i][1] = temp.back() - 1;
    }
    temp.push_back(i);
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (i - d[i][0] <= d[i][1] - i) {
      for (long long t = i - 1; t >= d[i][0]; t--) {
        long long x = b[i] - b[t];
        if (c[x] >= i && c[x] <= d[i][1]) ans++;
      }
    } else {
      for (long long t = i + 1; t <= d[i][1]; t++) {
        long long x = b[i] - b[t];
        if (c[x] <= i && c[x] >= d[i][0]) ans++;
      }
    }
  }
  cout << ans << "\n";
  return 0;
}
