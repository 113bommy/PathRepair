#include <bits/stdc++.h>
using namespace std;
inline void boost() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
const long long maxn = 2e5 + 123;
const long long inf = 1e9 + 123;
const long long linf = 1e18 + 123;
const long long mod = 1e9 + 7;
const double eps = 1e-9;
const double pi = acos(-1);
int dx[8] = {0, 1, -1, 0, 1, -1, 1, -1};
int dy[8] = {1, 0, 0, -1, 1, 1, -1, -1};
vector<long long> lucky;
void f(long long v) {
  if (v > 10000000000) {
    return;
  }
  lucky.push_back(v);
  f(v * 10 + 4);
  f(v * 10 + 7);
}
long long intersect(long long l, long long r, long long l1, long long r1) {
  if (l > r1 || l1 > r) {
    return 0;
  }
  if (l1 <= l && r <= r1) {
    return r - l + 1;
  }
  if (l <= l1 && r1 <= r) {
    return r1 - l1 + 1;
  }
  if (l1 <= r && r <= r1) {
    return r - l1 + 1;
  }
  if (l <= r1 && r1 <= r) {
    return r1 - l + 1;
  }
}
int main() {
  boost();
  f(4);
  f(7);
  sort(lucky.begin(), lucky.end());
  long long x, y, x1, y1, k;
  cin >> x >> y >> x1 >> y1 >> k;
  long double cntr = 0;
  for (long long i = 0; i + k < lucky.size(); i++) {
    if (i + k - 1 > lucky.size() - 1) {
      continue;
    }
    long long q = 0;
    if (i >= 1) {
      q = intersect(x, y, lucky[i - 1] + 1, lucky[i]);
    } else {
      q = intersect(x, y, 0, lucky[i]);
    }
    long long q1 = 0;
    long long j = i + k - 1;
    if (j <= lucky.size() - 1) {
      q1 = intersect(x1, y1, lucky[j], lucky[j + 1] - 1);
    } else {
      q1 = intersect(x1, y1, lucky[j], linf);
    }
    if (q1 < 0 || q < 0) {
      continue;
    }
    cntr += q * q1;
  }
  swap(x, x1);
  swap(y, y1);
  for (long long i = 0; i < lucky.size(); i++) {
    if (i + k - 1 > lucky.size() - 1) {
      continue;
    }
    long long q = 0;
    if (i >= 1) {
      q = intersect(x, y, lucky[i - 1] + 1, lucky[i]);
    } else {
      q = intersect(x, y, 0, lucky[i]);
    }
    long long q1 = 0;
    long long j = i + k - 1;
    if (j <= lucky.size() - 1) {
      q1 = intersect(x1, y1, lucky[j], lucky[j + 1] - 1);
    } else {
      q1 = intersect(x1, y1, lucky[j], linf);
    }
    if (q1 < 0 || q < 0) {
      continue;
    }
    cntr += q * q1;
  }
  if (k == 1) {
    for (int i = 1; i < lucky.size(); i++) {
      cntr -= intersect(lucky[i], lucky[i], x, y) *
              intersect(lucky[i], lucky[i], x1, y1);
    }
  }
  long double Q = (y - x + 1) * (y1 - x1 + 1);
  cout << fixed << setprecision(9) << cntr / Q;
  exit(0);
}
