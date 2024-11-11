#include <bits/stdc++.h>
using namespace std;
const int N = 2016;
bitset<N> v[N];
bitset<N> ones[N + 1];
set<pair<int, int> > bad;
void rem(int i, int j) {
  if (i > j) swap(i, j);
  bad.erase(pair<int, int>(i, j));
}
void check(int i, int j) {
  if (v[i] != (v[i] & v[j])) {
    if (i > j) swap(i, j);
    bad.insert(pair<int, int>(i, j));
  }
}
const int BB = 1 << 16;
int small[BB];
int smallest_bit(unsigned int v) {
  if (!v) return 1e9;
  unsigned int v1 = v & (BB - 1);
  if (v1)
    return small[v1];
  else
    return 16 + small[(v ^ v1) >> 16];
}
int get_first(int l, int r, const bitset<N>& a) {
  int ans = r;
  if (l >= r) return ans;
  const int B = 32;
  const unsigned int* c = reinterpret_cast<const unsigned int*>(&a);
  if (l / B == r / B) {
    ans = min(ans,
              l + smallest_bit((c[l / B] & ((1 << (r % B)) - 1)) >> (l % B)));
    return ans;
  }
  ans = min(ans, l + smallest_bit(c[l / B] >> (l % B)));
  for (int i = l / B + 1; i < r / B; ++i) {
    ans = min(ans, i * B + smallest_bit(c[i]));
  }
  if (r % B != 0) {
    ans = min(ans, r - 1 - (B - 1) + smallest_bit((c[r / B] << (B - r % B))));
  }
  return ans;
}
const int DEBUG = 0;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  for (int i = 2; i < BB; i += 2) small[i] = 1 + small[i / 2];
  int n = 4, m = 4, T = 2500000;
  if (!DEBUG) cin >> n >> m >> T;
  vector<vector<int> > deb(n, vector<int>(m));
  for (int i = 0; i < N; ++i) {
    ones[i + 1] = ones[i];
    ones[i + 1].set(i);
  }
  set<pair<int, int> > w;
  vector<int> sz(n);
  for (int i = 0; i < n; ++i) w.insert(pair<int, int>(sz[i], i));
  bitset<N> tmp;
  for (int q = 0; q < T; ++q) {
    int a = rand() % n + 1, l = rand() % m + 1, r = rand() % m + 1;
    if (l > r) swap(l, r);
    if (!DEBUG) cin >> a >> l >> r;
    --a;
    if (DEBUG)
      for (int i = l - 1; i <= r - 1; ++i) deb[a][i] ^= 1;
    auto it = w.find(pair<int, int>(sz[a], a));
    int pr = -1, nx = -1;
    if (it != w.begin()) {
      auto it1 = it;
      --it1;
      pr = it1->second;
      rem(it1->second, a);
    }
    auto it1 = it;
    ++it1;
    if (it1 != w.end()) {
      nx = it1->second;
      rem(a, it1->second);
    }
    if (pr != -1 && nx != -1) check(pr, nx);
    w.erase(pair<int, int>(sz[a], a));
    v[a] ^= ones[r] ^ ones[l - 1];
    sz[a] = v[a].count();
    it = w.insert(pair<int, int>(sz[a], a)).first;
    pr = -1, nx = -1;
    if (it != w.begin()) {
      auto it1 = it;
      --it1;
      pr = it1->second;
      check(pr, a);
    }
    it1 = it;
    ++it1;
    if (it1 != w.end()) {
      nx = it1->second;
      check(a, nx);
    }
    if (pr != -1 && nx != -1) rem(pr, nx);
    if (bad.empty()) {
      cout << "-1\n";
      if (DEBUG) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) cerr << deb[i][j];
          cerr << endl;
        }
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < m; ++j)
            for (int i1 = i + 1; i1 < n; ++i1)
              for (int j1 = j + 1; j1 < m; ++j1) {
                assert(!(deb[i][j] == deb[i1][j1] && deb[i][j1] == deb[i1][j] &&
                         deb[i][j] != deb[i][j1]));
              }
      }
    } else {
      int i = bad.begin()->first, j = bad.begin()->second;
      tmp = v[i] & v[j];
      int c1 = get_first(0, m, v[i] ^ tmp), c2 = get_first(0, m, v[j] ^ tmp);
      if (c1 > c2) swap(c1, c2);
      cout << i + 1 << ' ' << c1 + 1 << ' ' << j + 1 << ' ' << c2 + 1 << '\n';
      assert(c1 < m && c2 < m);
      if (DEBUG) {
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) assert(v[i][j] == deb[i][j]);
        }
        assert(deb[i][c1] == deb[j][c2] && deb[i][c2] == deb[j][c1] &&
               deb[i][c1] != deb[i][c2]);
      }
    }
  }
  return 0;
}
