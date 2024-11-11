#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:512000000")
using namespace std;
void solve();
void precalc();
clock_t start;
int testNumber = 1;
bool todo = true;
int main() {
  start = clock();
  int t = 1;
  cout.sync_with_stdio(0);
  cin.tie(0);
  precalc();
  cout.precision(10);
  cout << fixed;
  cin >> t;
  int testNum = 1;
  while (t--) {
    solve();
    ++testNumber;
  }
  return 0;
}
template <typename T>
T binpow(T q, T w, T mod) {
  if (!w) return 1 % mod;
  if (w & 1) return q * 1LL * binpow(q, w - 1, mod) % mod;
  return binpow(q * 1LL * q % mod, w / 2, mod);
}
void precalc() {}
template <typename T>
T gcd(T q, T w) {
  while (w) {
    q %= w;
    swap(q, w);
  }
  return q;
}
template <typename T>
T lcm(T q, T w) {
  return q / gcd(q, w) * w;
}
long long mult(const vector<long long>& a, long long mask) {
  long long res = a[2];
  for (long long i = 0; i < 2; ++i) {
    if (mask & (1 << i)) {
      res += a[i];
    } else {
      res -= a[i];
    }
  }
  return res;
}
long long get_floor(long long x) {
  long long res = x / 2 - 2;
  while (2 * res < x) {
    ++res;
  }
  return res;
}
long long get_ceil(long long x) {
  long long res = x / 2 - 5;
  while (2 * (res + 1) <= x) {
    ++res;
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  vector<vector<long long>> points(n, vector<long long>(3));
  set<long long> from_mask[4];
  for (long long i = 0; i < n; ++i) {
    for (long long j = 0; j < 3; ++j) {
      cin >> points[i][j];
    }
    for (long long mask = 0; mask < 4; ++mask) {
      from_mask[mask].insert(mult(points[i], mask));
    }
  }
  vector<vector<long long>> extr(4, vector<long long>(2));
  for (long long mask = 0; mask < 4; ++mask) {
    extr[mask][0] = *(from_mask[mask].begin());
    extr[mask][1] = *(from_mask[mask].rbegin());
  }
  long long L = -1, R = (long long)3e18 + 10;
  long long cur_x, cur_y, cur_z;
  while (L + 1 < R) {
    long long d = (L + R) / 2;
    vector<long long> min_val(4), max_val(4);
    bool f = true;
    for (long long mask = 0; mask < 4; ++mask) {
      max_val[mask] = extr[mask][0] + d;
      min_val[mask] = extr[mask][1] - d;
      if (min_val[mask] > max_val[mask]) {
        f = false;
        break;
      }
    }
    if (!f) {
      L = d;
      continue;
    }
    long long min_2x = max(min_val[1] - max_val[0], min_val[3] - max_val[2]);
    long long max_2x = min(max_val[1] - min_val[0], max_val[3] - min_val[2]);
    long long min_2y = max(min_val[2] - max_val[0], min_val[3] - max_val[1]);
    long long max_2y = min(max_val[2] - min_val[0], max_val[3] - min_val[1]);
    long long minx = get_floor(min_2x);
    long long miny = get_floor(min_2y);
    long long maxx = get_ceil(max_2x);
    long long maxy = get_ceil(max_2y);
    if (minx > maxx || miny > maxy) {
      L = d;
      continue;
    }
    long long min_2xy = min_val[3] - max_val[0];
    long long max_2xy = max_val[3] - min_val[0];
    long long min_sum = get_floor(min_2xy);
    long long max_sum = get_ceil(max_2xy);
    min_2xy = min_val[1] - max_val[2];
    max_2xy = max_val[1] - min_val[2];
    long long min_diff = get_floor(min_2xy);
    long long max_diff = get_ceil(max_2xy);
    if (min_sum > max_sum || min_diff > max_diff) {
      L = d;
      continue;
    }
    maxx = min(maxx, get_ceil(max_sum + max_diff));
    minx = max(minx, get_floor(min_sum + min_diff));
    minx = max(minx, min_sum - maxy);
    maxx = min(maxx, max_sum - miny);
    maxx = min(maxx, max_diff + maxy);
    minx = max(minx, min_diff + miny);
    if (minx > maxx) {
      L = d;
    } else {
      R = d;
      cur_x = minx;
      cur_y = max(max(miny, min_sum - cur_x), cur_x - min_diff);
      cur_z = max(min_val[0] + cur_x + cur_y, min_val[1] - cur_x + cur_y);
      cur_z = max(cur_z,
                  max(min_val[2] + cur_x - cur_y, min_val[3] - cur_x - cur_y));
    }
  }
  cout << cur_x << ' ' << cur_y << ' ' << cur_z << "\n";
}
