#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
const int MAXN = 1e4 + 10;
const int MOD = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1.0);
const double eps = 1e-6;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
long long a, b, c, l;
long long f(long long a, long long b, long long c) {
  long long res = 0;
  for (long long i = 0; i <= l; i++) {
    long long t = min(l - i, c + i - a - b);
    if (t > 0) res += (1LL) * (t + 1) * (t + 2) / 2;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> a >> b >> c >> l;
  cout << (1LL) * (l + 1) * (l + 2) * (l + 3) / ((long long)6) - f(a, b, c) -
              f(b, c, a) - f(c, a, b);
  return 0;
}
