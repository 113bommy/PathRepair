#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("-ffloat-store")
using namespace std;
clock_t time_p = clock();
void aryanc403() {
  time_p = clock() - time_p;
  cerr << "Time Taken : " << (float)(time_p) / CLOCKS_PER_SEC << "\n";
}
const long long int INF = 0xFFFFFFFFFFFFFFFL;
long long int seed;
mt19937 rng(seed = chrono::steady_clock::now().time_since_epoch().count());
inline long long int rnd(long long int l = 0, long long int r = INF) {
  return uniform_int_distribution<long long int>(l, r)(rng);
}
class CMP {
 public:
  bool operator()(pair<long long int, long long int> a,
                  pair<long long int, long long int> b) {
    return !(a.first < b.first || a.first == b.first && a.second <= b.second);
  }
};
void add(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt == m.end())
    m.insert({x, cnt});
  else
    jt->second += cnt;
}
void del(map<long long int, long long int> &m, long long int x,
         long long int cnt = 1) {
  auto jt = m.find(x);
  if (jt->second <= cnt)
    m.erase(jt);
  else
    jt->second -= cnt;
}
bool cmp(const pair<long long int, long long int> &a,
         const pair<long long int, long long int> &b) {
  return a.first < b.first || (a.first == b.first && a.second < b.second);
}
const long long int mod = 998244353L;
namespace ntt {
const long long int MAGIC = 200;
const long long int mod = (119LL << 23) + 1, root = 3;
long long int modpow(long long int a, long long int e) {
  if (e == 0) return 1;
  long long int x = modpow(a * a % mod, e >> 1);
  return e & 1 ? x * a % mod : x;
}
void ntt(long long int *x, long long int *temp, long long int *roots,
         long long int N, long long int skip) {
  if (N == 1) return;
  long long int n2 = N / 2;
  ntt(x, temp, roots, n2, skip * 2);
  ntt(x + skip, temp, roots, n2, skip * 2);
  for (long long int i = 0; i < (N); ++i) temp[i] = x[i * skip];
  for (long long int i = 0; i < (n2); ++i) {
    long long int s = temp[2 * i], t = temp[2 * i + 1] * roots[skip * i];
    x[skip * i] = (s + t) % mod;
    x[skip * (i + n2)] = (s - t) % mod;
  }
}
void ntt(vector<long long int> &x, bool inv = false) {
  long long int e = modpow(root, (mod - 1) / (long long int)(x).size());
  if (inv) e = modpow(e, mod - 2);
  vector<long long int> roots((long long int)(x).size(), 1), temp = roots;
  for (long long int i = 1; i <= ((long long int)(x).size() - 1); ++i)
    roots[i] = roots[i - 1] * e % mod;
  ntt(&x[0], &temp[0], &roots[0], (long long int)(x).size(), 1);
}
void conv(vector<long long int> &c, vector<long long int> a,
          vector<long long int> b) {
  long long int s = (long long int)(a).size() + (long long int)(b).size() - 1;
  if (s <= 0) {
    c.clear();
    return;
  }
  long long int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
  if (s <= MAGIC) {
    c.clear();
    c.resize(s, 0);
    for (long long int i = 0; i < ((long long int)(a).size()); ++i)
      for (long long int j = 0; j < ((long long int)(b).size()); ++j)
        c[i + j] = (c[i + j] + a[i] * b[j]) % mod;
    return;
  }
  a.resize(n, 0);
  ntt(a);
  b.resize(n, 0);
  ntt(b);
  c.clear();
  c.resize(n, 0);
  long long int d = modpow(n, mod - 2);
  for (long long int i = 0; i < (n); ++i) c[i] = a[i] * b[i] % mod * d % mod;
  ntt(c, true);
  c.resize(s);
  for (auto &x : c) {
    if (x < 0) x += mod;
  }
}
void conv2(vector<long long int> &c, vector<long long int> a) {
  long long int s = 2 * (long long int)(a).size() - 1;
  if (s <= 0) {
    c.clear();
    return;
  }
  long long int L = s > 1 ? 32 - __builtin_clz(s - 1) : 0, n = 1 << L;
  if (s <= MAGIC) {
    c.clear();
    c.resize(s, 0);
    for (long long int i = 0; i < ((long long int)(a).size()); ++i)
      for (long long int j = 0; j < ((long long int)(a).size()); ++j)
        c[i + j] = (c[i + j] + a[i] * a[j]) % mod;
    return;
  }
  a.resize(n, 0);
  ntt(a);
  c.clear();
  c.resize(n, 0);
  long long int d = modpow(n, mod - 2);
  for (long long int i = 0; i < (n); ++i) c[i] = a[i] * a[i] % mod * d % mod;
  ntt(c, true);
  c.resize(s);
  for (auto &x : c) {
    if (x < 0) x += mod;
  }
}
}  // namespace ntt
const long long int N = 1000000L;
long long int T, n, i, j, k, in, cnt, l, r, u, v, x, y;
long long int m;
string s;
vector<long long int> a, ans;
void reduce(vector<long long int> &a) {
  for (auto &x : a) x = (x > 0);
  if ((long long int)a.size() <= N) return;
  a.resize(N + 1);
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  {
    cin >> n >> k;
    a.clear();
    a.resize(1024, 0);
    for (i = 0; i < (n); ++i) {
      cin >> in;
      a[in] = 1;
    }
    ans.push_back(1);
    while (k) {
      if (k & 1) {
        ntt::conv(ans, ans, a);
        reduce(ans);
      }
      k /= 2;
      ntt::conv2(a, a);
      reduce(a);
    }
    n = min(N, (long long int)ans.size() - 1);
    for (i = (1); i <= (n); ++i) {
      if (ans[i]) cout << i << " ";
    }
    cout << "\n";
  }
  aryanc403();
  return 0;
}
