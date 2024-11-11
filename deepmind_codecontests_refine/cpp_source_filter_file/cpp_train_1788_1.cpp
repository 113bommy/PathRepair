#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1000000007;
ll binpow(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = (res * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
ll modInv(ll a) { return binpow(a, MOD - 2); }
const double PI = acos(-1);
const int INF = 0x3f3f3f3f;
const int NINF = 0x3f3f3f40;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll NINFLL = 0x3f3f3f3f3f3f3f40;
const int mxN = 1001;
int board[mxN][mxN];
int psum[mxN][mxN];
ll n, m, q;
ll sum = 0;
int gettype(ll x) {
  if (x == 1) return 1;
  int nxt = 1;
  while (x > 2 * nxt) {
    nxt *= 2;
  }
  return gettype(x - nxt) ^ 1;
}
ll solve(int x, int y) {
  if (x == 0 || y == 0) return 0;
  ll numx = x / n;
  ll fieldx = numx + 1;
  ll numy = y / m;
  ll fieldy = numy + 1;
  ll overx = x % n;
  ll overy = y % m;
  ll res = 0;
  ll numones = numx / 2 * sum + numx / 2 * (n * m - sum);
  if (numx & 1) {
    if (gettype(numx))
      numones += sum;
    else
      numones += n * m - sum;
  }
  res += numy / 2 * numones + numy / 2 * (1LL * n * m * numx - numones);
  if (numy & 1) {
    if (gettype(numy))
      res += numones;
    else
      res += 1LL * n * m * numx - numones;
  }
  if (overx) {
    if (gettype(fieldx)) {
      numones = psum[overx][m];
    } else {
      numones = overx * m - psum[overx][m];
    }
    res += numy / 2 * numones + numy / 2 * (overx * m - numones);
    if (numy & 1) {
      if (gettype(numy))
        res += numones;
      else
        res += overx * m - numones;
    }
  }
  if (overy) {
    if (gettype(fieldy)) {
      numones = psum[n][overy];
    } else {
      numones = overy * n - psum[n][overy];
    }
    res += numx / 2 * numones + numx / 2 * (overy * n - numones);
    if (numx & 1) {
      if (gettype(numx))
        res += numones;
      else
        res += overy * n - numones;
    }
  }
  if (overx && overy) {
    if (gettype(fieldx) ^ gettype(fieldy) == 0) {
      res += psum[overx][overy];
    } else {
      res += (overx * overy - psum[overx][overy]);
    }
  }
  return res;
}
int main() {
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> q;
  string s;
  for (int i = (0); i < (n); ++i) {
    cin >> s;
    for (int j = (0); j < (m); ++j) {
      board[i][j] = s[j] == '1';
      sum += board[i][j];
    }
  }
  for (int i = (0); i < (n + 1); ++i) {
    for (int j = (0); j < (m + 1); ++j) {
      psum[i + 1][j + 1] =
          psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + board[i][j];
    }
  }
  int x1, y1, x2, y2;
  while (q--) {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << (solve(x2, y2) - solve(x1 - 1, y2) - solve(x2, y1 - 1) +
             solve(x1 - 1, y1 - 1))
         << "\n";
  }
  return 0;
}
