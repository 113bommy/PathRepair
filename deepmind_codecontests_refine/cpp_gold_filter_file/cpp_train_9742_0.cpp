#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int MAXK = -1;
const int MAXN = -1;
const int MOD = 1000 * 1000 * 1000 + 7;
void add(int &x, int y) {
  x += y;
  if (x >= MOD) x -= MOD;
}
int bin(int a, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1LL * res * a % MOD;
    a = 1LL * a * a % MOD;
    n >>= 1;
  }
  return res;
}
template <const int max_size, class HashType, class Data,
          const Data default_value>
struct hashTable {
  HashType hash[max_size];
  Data f[max_size];
  int size;
  int position(HashType H) const {
    int i = H % max_size;
    while (hash[i] && hash[i] != H)
      if (++i == max_size) i = 0;
    return i;
  }
  Data &operator[](HashType H) {
    H++;
    assert(H != 0);
    int i = position(H);
    if (!hash[i]) {
      hash[i] = H;
      f[i] = default_value;
      size++;
    }
    return f[i];
  }
  void clear() {
    size = 0;
    memset(hash, 0, sizeof(hash));
  }
};
const int N = (int)(1.2e7 + 3);
hashTable<N, long long, int, 0> mp, nmp;
int solve(string s, vector<pair<int, int> > a) {
  int n = a.size();
  int m = s.length();
  for (int i = 0; i < m; i++) {
    s[i] = (char)('1' - (s[i] - '0'));
  }
  long long need = 0;
  for (int i = 0; i < m; i++) need += ((long long)(s[i] == '1')) << i;
  int bits = __builtin_popcountll(need);
  long long all = (1LL << m) - 1;
  bool sooqa = a[0].first == 2276909;
  sort(a.begin(), a.end());
  if (sooqa) {
    int T = sqrt(1.01e9);
    vector<char> isPrime(T, 1);
    vector<int> pr;
    for (int i = 2; i < T; i++) {
      if (isPrime[i]) {
        pr.push_back(i);
        for (int j = i + i; j < T; j += i) {
          isPrime[j] = 0;
        }
      }
    }
    const int MX = (int)(1e9);
    for (int i = 0; i < n; i++) {
      assert(a[i].first >= 1 && a[i].first <= MX && a[i].second >= 1 &&
             a[i].second <= MX);
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; pr[j] * pr[j] <= a[i].first; j++)
        assert(a[i].first % pr[j] != 0);
    }
  }
  mp.clear();
  mp[0] = 1;
  vector<vector<long long> > frst(m, vector<long long>(m + 1));
  vector<vector<long long> > bb(m, vector<long long>(m));
  for (int i = 0; i < m; i++) {
    int cnt = 0;
    long long cur = 0;
    long long aa = 0;
    for (int j = i; j < m; j++) {
      if (need & (1LL << j)) {
        cnt++;
        cur |= 1LL << j;
        frst[i][cnt] = cur;
      }
      aa |= 1LL << j;
      bb[i][j] = aa;
    }
  }
  int i;
  vector<int> dp(m + 2);
  int oo = 0;
  while (oo < n && a[oo].first * 2 + 1 <= m) oo++;
  for (i = 0; i < n && a[i].first < m; i++) {
    long long mask = 0;
    for (int j = 0; j < m; j += a[i].first) mask |= 1LL << j;
    nmp.clear();
    int nxt = min((i + 1 < (int)a.size() ? a[i + 1].first : m), m);
    vector<long long> ok;
    for (int j = 0; j < a[i].first; j++)
      if ((((mask << j) & all) | need) == need) ok.push_back((mask << j) & all);
    for (int ii = 0; ii < N; ii++)
      if (mp.hash[ii]) {
        auto it = make_pair(mp.hash[ii] - 1, mp.f[ii]);
        long long cmask = it.first;
        for (const long long &j : ok) {
          long long nmask = (cmask | j);
          if (nxt == m) {
            add(dp[__builtin_popcountll(need ^ nmask)], it.second);
          } else {
            if (nxt * 2 + 1 > m) {
              int L = m - nxt;
              int R = nxt - 1;
              long long omask = bb[L][R];
              int cc = __builtin_popcountll(nmask & omask);
              nmask = (nmask & (~omask)) | frst[L][cc];
            }
            add(nmp[nmask], it.second);
          }
        }
      }
    mp = nmp;
  }
  if (a[0].first >= m)
    for (int i = 0; i < N; i++)
      if (mp.hash[i]) {
        auto it = make_pair(mp.hash[i] - 1, mp.f[i]);
        add(dp[__builtin_popcountll(need ^ it.first)], it.second);
      }
  for (; i < n; i++) {
    for (int j = 0; j <= m; j++) {
      dp[j] = (1LL * dp[j + 1] * (j + 1) +
               1LL * dp[j] * (a[i].first - j - m + bits)) %
              MOD;
    }
  }
  int ans = dp[0];
  for (int i = 0; i < n; i++)
    ans = 1LL * ans * bin(a[i].first, a[i].second - 1) % MOD;
  return ans;
}
char buf[111];
bool prime(int x) {
  for (int i = 2; i * i <= x; i++)
    if (x % i == 0) return 0;
  return 1;
}
int main() {
  if (0) {
    vector<pair<int, int> > a;
    for (int i = 5; i <= 71; i++)
      if (prime(i)) a.push_back(make_pair(i, 1));
    string s(39, '0');
    cout << solve(s, a) << endl;
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
  }
  if (0) {
    int n = 5e5;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) a[i] = make_pair((int)(9e8) + i, (1 << 29) - 1);
    string s(40, '0');
    cout << solve(s, a) << endl;
    cerr << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
  }
  string s;
  int n;
  while (scanf("%s%d", buf, &n) == 2) {
    s = buf;
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].first, &a[i].second);
    cout << solve(s, a) << endl;
  }
  cerr << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
