#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
struct mat {
  long long m[11][11];
  mat() { memset(m, 0, sizeof m); }
};
mat Identidade() {
  mat c;
  for (int i = 0; i <= 10; i++) c.m[i][i] = 1;
  return c;
}
long long k2 = 0;
mat mult(mat a, mat b) {
  mat c;
  for (int j = 0; j <= 10; j++) {
    for (int k = 0; k <= 10; k++) {
      for (int i = 0; i <= 10; i++) {
        if (c.m[i][j] >= k2) {
          c.m[i][j] = k2;
          continue;
        }
        if (b.m[k][j] > 0LL &&
            (k2 + b.m[k][j] - 1LL) / b.m[k][j] <= a.m[i][k]) {
          c.m[i][j] = k2;
          continue;
        }
        c.m[i][j] += a.m[i][k] * b.m[k][j];
      }
    }
  }
  return c;
}
mat fast_exp(mat base, long long exp) {
  if (exp == 0ll) return Identidade();
  mat x = fast_exp(base, exp >> 1);
  if (exp & 1ll) return mult(base, mult(x, x));
  return mult(x, x);
}
long long n, k;
bool check(long long mid) {
  mat grid;
  for (int i = 0; i < (int)(11); i++) {
    for (int j = 0; j < (int)(11); j++) {
      if (i >= j) grid.m[i][j] = 1ll;
    }
  }
  grid = fast_exp(grid, mid);
  for (int i = 0; i < (int)(n); i++) {
    long long c = 0;
    for (int j = 0; j < (int)(n); j++) {
      if (grid.m[i][j] > 0LL && (k + grid.m[i][j] - 1LL) / grid.m[i][j] <= v[j])
        return 1;
      c += grid.m[i][j] * v[j];
      if (c >= k) return true;
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  k2 = k;
  v.resize(n);
  for (int i = 0; i < (int)(n); i++) {
    cin >> v[i];
  }
  reverse(v.begin(), v.end());
  while (v.back() == 0) v.pop_back();
  reverse(v.begin(), v.end());
  n = v.size();
  if (n > 10) {
    int cont = 0;
    if (v[0] >= k) {
      cout << cont << '\n';
      return 0;
    }
    while (1) {
      for (int i = 1; i < (int)(n); i++) {
        if (v[i] >= k) {
          cout << cont << '\n';
          return 0;
        }
        v[i] += v[i - 1];
      }
      cont++;
    }
  } else {
    long long lo = 0LL, hi = 1000000000000000001LL, mid;
    while (lo <= hi) {
      mid = (lo + hi) >> 1;
      if (check(mid)) {
        hi = mid - 1LL;
      } else {
        lo = mid + 1LL;
      }
    }
    cout << hi + 1LL << '\n';
  }
  return 0;
}
