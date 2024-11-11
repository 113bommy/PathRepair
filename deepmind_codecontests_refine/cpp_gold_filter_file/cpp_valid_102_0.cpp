#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int k, A, h;
const int mod = 998244353;
long long pa[33], ans[33], val[33], inv[10];
long long powmod(long long a, long long b) {
  long long res = 1;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
bool rec_find(vector<int> &p, int k, long long curans) {
  if (k == 0) {
    long long temp = (curans + A * 1ll * p[0] % mod) % mod;
    if (temp == h) {
      ans[p[0]] = 1;
      return 1;
    }
    return 0;
  }
  int ubl = (1 << (k - 1));
  ubl = (1 << ubl);
  for (int i = 0; i < ubl; ++i) {
    long long temp = curans;
    vector<int> nxt((1 << (k - 1)));
    for (int r = 0, j = 0; r < (1 << k); r += 2, ++j) {
      if ((i & (1 << j))) {
        nxt[j] = p[r];
        temp = (temp + p[r + 1] * 1ll * pa[1 + (1 << (k - 1))]) % mod;
      } else {
        nxt[j] = p[r + 1];
        temp = (temp + p[r] * 1ll * pa[1 + (1 << (k - 1))]) % mod;
      }
    }
    if (rec_find(nxt, k - 1, temp)) {
      for (int r = 0, j = 0; r < (1 << k); r += 2, ++j) {
        if ((i & (1 << j)))
          ans[p[r + 1]] = 1 + (1 << (k - 1));
        else
          ans[p[r]] = 1 + (1 << (k - 1));
      }
      return 1;
    }
  }
  return 0;
}
void s1(vector<int> p, int k, long long curans, vector<vector<long long>> &ps,
        vector<vector<long long>> &ts) {
  if (k == 0) {
    long long temp = (curans + pa[2] * 1ll * p[0] % mod) % mod;
    ans[p[0]] = 2;
    long long t2 = 0;
    for (int i = 1; i <= 16; ++i) {
      if (p[0] <= 16)
        t2 = 10 * t2 + val[ans[i]];
      else
        t2 = 10 * t2 + val[ans[i + 16]];
    }
    ps[p[0] - 1].push_back(temp);
    ts[p[0] - 1].push_back(t2);
    return;
  }
  int ubl = (1 << (k - 1));
  ubl = (1 << ubl);
  for (int i = 0; i < ubl; ++i) {
    long long temp = curans;
    vector<int> nxt((1 << (k - 1)));
    for (int r = 0, j = 0; r < (1 << k); r += 2, ++j) {
      if ((i & (1 << j))) {
        nxt[j] = p[r];
        ans[p[r + 1]] = 1 + (1 << (k));
        temp = (temp + p[r + 1] * 1ll * pa[1 + (1 << (k))]) % mod;
      } else {
        nxt[j] = p[r + 1];
        ans[p[r]] = 1 + (1 << (k));
        temp = (temp + p[r] * 1ll * pa[1 + (1 << (k))]) % mod;
      }
    }
    s1(nxt, k - 1, temp, ps, ts);
  }
}
void solve() {
  cin >> k >> A >> h;
  pa[0] = 1;
  val[1] = 1;
  val[2] = 2;
  val[3] = 3;
  val[5] = 4;
  val[9] = 5;
  val[17] = 6;
  inv[6] = 17;
  inv[5] = 9;
  inv[4] = 5;
  inv[3] = 3;
  inv[2] = 2;
  inv[1] = 1;
  for (int i = 1; i < 33; ++i) pa[i] = (A * 1ll * pa[i - 1]) % mod;
  if (k != 5) {
    vector<int> p((1 << k));
    for (int i = 0; i < ((1 << k)); i++) p[i] = i + 1;
    if (rec_find(p, k, 0)) {
      for (int i = 1; i < ((1 << k) + 1); i++) cout << ans[i] << ' ';
      cout << "\n";
    } else
      cout << "-1\n";
    return;
  }
  vector<int> p(16);
  for (int i = 0; i < (16); i++) p[i] = i + 1;
  vector<vector<long long>> a(33), b(33);
  s1(p, 4, 0, a, b);
  for (int i = 0; i < (16); i++) p[i] = 17 + i;
  s1(p, 4, 0, a, b);
  vector<map<int, int>> M(32);
  for (int i = 0; i < (32); i++) {
    for (int k = 0; k < (a[i].size()); k++) M[i][a[i][k]] = k + 1;
  }
  for (int i = 0; i < (32); i++) {
    long long th = (h + ((i + 1) * 1ll * (pa[2] - A)) % mod) % mod;
    for (int k = 0; k < (a[i].size()); k++) {
      long long fi = (th - a[i][k]) % mod;
      if (fi < 0) fi += mod;
      assert(fi >= 0);
      for (int j = 0; j < (16); j++) {
        if (i < 16) {
          int pos = M[j + 16][fi];
          if (pos) {
            --pos;
            long long V = b[i][k], term = 16;
            while (V) {
              int c = inv[V % 10];
              if (c == 2) c = 1;
              ans[term--] = c;
              V /= 10;
            }
            V = b[j + 16][pos], term = 32;
            while (V) {
              int c = inv[V % 10];
              ans[term--] = c;
              V /= 10;
            }
            for (int ri = 1; ri < (33); ri++) cout << ans[ri] << ' ';
            cout << "\n";
            return;
          }
        } else {
          int pos = M[j][fi];
          if (pos) {
            --pos;
            long long V = b[i][k], term = 32;
            while (V) {
              int c = inv[V % 10];
              if (c == 2) c = 1;
              ans[term--] = c;
              V /= 10;
            }
            V = b[j][pos], term = 16;
            while (V) {
              int c = inv[V % 10];
              ans[term--] = c;
              V /= 10;
            }
            for (int ri = 1; ri < (33); ri++) cout << ans[ri] << ' ';
            cout << "\n";
            return;
          }
        }
      }
    }
  }
  cout << "-1\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t = 1, Tc = 1;
  while (t--) {
    solve();
  }
  return 0;
}
