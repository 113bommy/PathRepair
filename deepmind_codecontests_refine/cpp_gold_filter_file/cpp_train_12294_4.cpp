#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
const int MOD = 998244353;
const int PRIMROOT = 3;
int pw(int x, int n) {
  int ret = 1;
  while (true) {
    if (n & 1) ret = (long long)ret * x % MOD;
    if ((n >>= 1) == 0) return ret;
    x = (long long)x * x % MOD;
  }
}
struct NTT {
  void _init(int n, int &nlog, int &g, vector<int> &w) {
    assert((MOD - 1) % n == 0);
    g = pw(PRIMROOT, (MOD - 1) / n);
    nlog = 0;
    while ((1 << nlog) < n) ++nlog;
    if ((1 << nlog) != n) nlog = -1;
    w = vector<int>(n);
    w[0] = 1;
    for (int i = (1); i < (n); ++i) w[i] = (long long)w[i - 1] * g % MOD;
  }
  int fftn, fftnlog;
  int fftg;
  vector<int> fftw;
  void initfft(int n) {
    fftn = n, _init(fftn, fftnlog, fftg, fftw);
    assert(fftnlog != -1);
  }
  void fft(int *a, int n, bool inv) {
    if (n != fftn) initfft(n);
    for (int i = 1, j = n >> 1, k, l = j; i < n; j ^= k, ++i) {
      if (i < j) swap(a[i], a[j]);
      for (k = l; k & j; j ^= k, k >>= 1)
        ;
    }
    int *l, *r, *w;
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    for (int hlen = 1, step = n >> 1; hlen < n; hlen <<= 1, step >>= 1) {
      for (int i = 0; i < n; i += (hlen << 1)) {
        l = a + i, r = l + hlen, w = fftw.data();
        for (int off = (0); off < (hlen); ++off) {
          int v = (long long)(*r) * (*w) % MOD;
          *r = (*l) - v;
          if (*r < 0) *r += MOD;
          *l = (*l) + v;
          if (*l >= MOD) *l -= MOD;
          ++l, ++r, w += step;
        }
      }
    }
    if (inv) reverse(fftw.begin() + 1, fftw.end());
    if (inv) {
      int mlt = pw(n, MOD - 2);
      for (int i = (0); i < (n); ++i) a[i] = (long long)a[i] * mlt % MOD;
    }
  }
  void mult(const int *a, int na, const int *b, int nb, int *c, int nc) {
    int sz = 1;
    while (sz < na + nb - 1) sz *= 2;
    vector<int> A(sz, 0), B(sz, 0);
    for (int i = (0); i < (na); ++i) A[i] = a[i];
    for (int i = (0); i < (nb); ++i) B[i] = b[i];
    fft(A.data(), sz, false);
    fft(B.data(), sz, false);
    for (int i = (0); i < (sz); ++i) A[i] = (long long)A[i] * B[i] % MOD;
    fft(A.data(), sz, true);
    for (int i = (0); i < (nc); ++i) c[i] = i < sz ? A[i] : 0;
  }
};
NTT ntt;
void inc(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}
vector<int> add(const vector<int> &a, const vector<int> &b) {
  vector<int> c(max(((int)(a).size()), ((int)(b).size())), 0);
  for (int i = (0); i < (((int)(c).size())); ++i) {
    if (i < ((int)(a).size())) inc(c[i], a[i]);
    if (i < ((int)(b).size())) inc(c[i], b[i]);
  }
  return c;
}
vector<int> mult(const vector<int> &a, const vector<int> &b) {
  vector<int> c(((int)(a).size()) + ((int)(b).size()) - 1, 0);
  ntt.mult(a.data(), ((int)(a).size()), b.data(), ((int)(b).size()), c.data(),
           ((int)(c).size()));
  return c;
}
const int MAXN = 100000;
int n;
long long want;
vector<int> adj[MAXN];
int par[MAXN];
int sz[MAXN];
int dep[MAXN];
int heavy[MAXN];
vector<int> ways[MAXN];
vector<int> waysnonheavy[MAXN];
void dfsinit(int at) {
  dep[at] = par[at] == -1 ? 0 : dep[par[at]] + 1, sz[at] = 1, heavy[at] = -1;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at]) continue;
    par[to] = at;
    dfsinit(to);
    sz[at] += sz[to];
    if (heavy[at] == -1 || sz[to] > sz[heavy[at]]) heavy[at] = to;
  }
}
int path[MAXN], npath;
pair<vector<int>, vector<int>> rec(int l, int r) {
  if (l == r) {
    int at = path[l];
    return make_pair(waysnonheavy[at], waysnonheavy[at]);
  } else {
    int m = l + (r - l) / 2;
    auto res1 = rec(l, m);
    auto res2 = rec(m + 1, r);
    return make_pair(add(res1.first, mult(res1.second, res2.first)),
                     mult(res1.second, res2.second));
  }
}
int lst[MAXN], nlst;
vector<int> tmp[2 * MAXN];
int ntmp;
priority_queue<pair<int, int>> pq;
void calcways(int at);
void calcwaysnonheavy(int at) {
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at] || to == heavy[at]) continue;
    calcways(to);
  }
  nlst = 0;
  for (int i = (0); i < (((int)(adj[at]).size())); ++i) {
    int to = adj[at][i];
    if (to == par[at] || to == heavy[at]) continue;
    lst[nlst++] = to;
  }
  ntmp = nlst;
  pq = priority_queue<pair<int, int>>();
  for (int i = (0); i < (nlst); ++i)
    tmp[i] = ways[lst[i]], pq.push(make_pair(-((int)(tmp[i]).size()), i));
  while (((int)(pq).size()) >= 2) {
    int a = pq.top().second;
    pq.pop();
    int b = pq.top().second;
    pq.pop();
    int c = ntmp++;
    tmp[ntmp] = mult(tmp[a], tmp[b]),
    pq.push(make_pair(-((int)(tmp[c]).size()), c));
  }
  waysnonheavy[at] =
      ((int)(pq).size()) == 1 ? tmp[pq.top().second] : vector<int>(1, 1);
  waysnonheavy[at].insert(waysnonheavy[at].begin(), 0);
  for (int i = (0); i < (ntmp); ++i) tmp[i].clear();
}
void calcways(int at) {
  for (int x = at; x != -1; x = heavy[x]) calcwaysnonheavy(x);
  npath = 0;
  for (int x = at; x != -1; x = heavy[x]) path[npath++] = x;
  ways[at] = rec(0, npath - 1).first;
  inc(ways[at][0], 1);
}
int inv[MAXN + 1];
void run() {
  scanf("%d%lld", &n, &want);
  for (int i = (0); i < (n - 1); ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  par[0] = -1;
  dfsinit(0);
  calcways(0);
  int ret = 0, mlt = 1;
  inv[1] = 1;
  for (int i = (2); i < (((int)(ways[0]).size())); ++i)
    inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
  for (int i = (1); i < (((int)(ways[0]).size())); ++i) {
    ret = (ret + (long long)ways[0][i] * mlt) % MOD;
    mlt = (long long)mlt * (want % MOD + i) % MOD * inv[i] % MOD;
  }
  printf("%d\n", ret);
}
int main() {
  run();
  return 0;
}
