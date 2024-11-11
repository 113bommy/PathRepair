#include <bits/stdc++.h>
using namespace std;
long long int recpow(long long int x, long long int n) {
  if (n == 0)
    return 1;
  else if (n % 2 == 0)
    return recpow((x * x) % 1000000007, n / 2);
  else
    return (x * recpow((x * x) % 1000000007, (n - 1) / 2)) % 1000000007;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
void multiply(long long int f[2][2], long long int m[2][2]) {
  long long int x = (f[0][0] % 1000000007 * m[0][0] % 1000000007) % 1000000007 +
                    (f[0][1] % 1000000007 * m[1][0] % 1000000007) % 1000000007;
  long long int y = (f[0][0] % 1000000007 * m[0][1] % 1000000007) % 1000000007 +
                    (f[0][1] % 1000000007 * m[1][1] % 1000000007) % 1000000007;
  long long int z = (f[1][0] % 1000000007 * m[0][0] % 1000000007) % 1000000007 +
                    (f[1][1] % 1000000007 * m[1][0] % 1000000007) % 1000000007;
  long long int w = (f[1][0] % 1000000007 * m[0][1] % 1000000007) % 1000000007 +
                    (f[1][1] % 1000000007 * m[1][1] % 1000000007) % 1000000007;
  f[0][0] = x % 1000000007;
  f[0][1] = y % 1000000007;
  f[1][0] = z % 1000000007;
  f[1][1] = w % 1000000007;
}
long long int u[2][2] = {{1, 1}, {1, 0}};
void power(long long int f[2][2], long long int n) {
  if (n == 0 || n == 1) return;
  power(f, n / 2);
  multiply(f, f);
  if (n % 2 != 0) multiply(f, u);
}
long long int fib(long long int n) {
  if (n == 1)
    return 2;
  else if (n == 2)
    return 3;
  else {
    long long int h[2][2] = {{1, 1}, {1, 0}};
    power(h, n + 1);
    return h[0][0];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int n, m;
  cin >> n >> m;
  long long int mh = 0, i, x, y, r = 1, j;
  vector<pair<long long int, long long int> > a;
  for (i = 0; i < m; ++i) {
    cin >> x >> y;
    if (y > mh) mh = y;
    a.push_back(make_pair(x, y));
  }
  if (a[0].first + a[0].second - 1 > mh) mh = a[0].first + a[0].second - 1;
  if (n - a[m - 1].first + a[m - 1].second > mh)
    mh = n - a[m - 1].first + a[m - 1].second;
  for (i = 0; i < m - 1; ++i) {
    if (abs(a[i].first - a[i + 1].first) < abs(a[i].second - a[i + 1].second)) {
      r = 0;
      break;
    } else if (abs(a[i].first - a[i + 1].first) >
               abs(a[i].second - a[i + 1].second)) {
      x = a[i + 1].first - a[i].first;
      if (a[i].second < a[i + 1].second) {
        y = a[i + 1].second - a[i].second;
        j = a[i + 1].second + (x - y) / 2;
        if (mh < j) mh = j;
      } else {
        y = a[i].second - a[i + 1].second;
        j = a[i].second + (x - y) / 2;
        if (mh < j) mh = j;
      }
    }
  }
  if (r == 0)
    cout << "IMPOSSIBLE" << endl;
  else
    cout << mh << endl;
  return 0;
}
