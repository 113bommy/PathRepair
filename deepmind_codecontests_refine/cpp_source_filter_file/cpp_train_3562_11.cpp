#include <bits/stdc++.h>
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int64_t maxn = 6e5 + 42;
int64_t par[maxn];
vector<int64_t> comp[maxn], extra[maxn];
int64_t color[maxn], inv[maxn], cnt[maxn], forced[maxn];
int64_t total;
int64_t get(int64_t v) { return v == par[v] ? v : par[v] = get(par[v]); }
int64_t getb(int64_t v) { return inv[v] ? comp[v].size() - cnt[v] : cnt[v]; }
int64_t getw(int64_t v) { return inv[v] ? cnt[v] : comp[v].size() - cnt[v]; }
int64_t getc(int64_t v) { return color[v] ^ inv[get(v)]; }
void uni(int64_t a, int64_t b) {
  int64_t A = get(a);
  int64_t B = get(b);
  if (comp[A].size() < comp[B].size()) {
    swap(A, B);
    swap(a, b);
  }
  if (A != B) {
    total -= getb(A) + getb(B);
    int64_t ca = getc(a);
    int64_t cb = getc(b);
    if (ca == cb) {
      int64_t bA = getb(A);
      int64_t wA = getw(A);
      int64_t bB = getb(B);
      int64_t wB = getw(B);
      if (!forced[A] && (bA - wA > bB - wB || forced[B])) {
        inv[A] ^= 1;
      } else {
        inv[B] ^= 1;
      }
    }
    par[B] = A;
    forced[A] |= forced[B];
    cnt[A] += (inv[B] == inv[A]) ? cnt[B] : comp[B].size() - cnt[B];
    for (auto it : comp[B]) {
      color[it] ^= inv[A] ^ inv[B];
      comp[A].push_back(it);
    }
    for (auto it : extra[B]) {
      color[it] ^= inv[A] ^ inv[B];
      extra[A].push_back(it);
    }
    total += getb(A);
  }
}
void force(int64_t v, int64_t c) {
  forced[get(v)] = 1;
  if (getc(v) != c) {
    v = get(v);
    total -= getb(v);
    inv[v] ^= 1;
    total += getb(v);
  }
}
void solve() {
  iota(par, par + maxn, 0);
  int64_t n, k;
  cin >> n >> k;
  for (int64_t i = 0; i < n; i++) {
    comp[i] = {i};
  }
  for (int64_t i = n; i < maxn; i++) {
    extra[i] = {i};
  }
  string s;
  cin >> s;
  int64_t sz = n;
  vector<int64_t> sets[n];
  for (int64_t i = 0; i < k; i++) {
    int64_t c;
    cin >> c;
    for (int64_t j = 0; j < c; j++) {
      int64_t t;
      cin >> t;
      sets[t - 1].push_back(i);
    }
  }
  for (int64_t i = 0; i < n; i++) {
    if (s[i] == '0') {
      if (sets[i].size() == 1) {
        force(sets[i][0], 1);
      } else {
        uni(sets[i][0], sets[i][1]);
      }
    } else {
      if (sets[i].size() == 1) {
        force(sets[i][0], 0);
      } else if (sets[i].size() == 2) {
        uni(sets[i][0], sz);
        uni(sets[i][1], sz);
        sz++;
      }
    }
    cout << total << "\n";
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int64_t t;
  t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
