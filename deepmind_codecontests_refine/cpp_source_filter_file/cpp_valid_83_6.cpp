#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INF64 = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
typedef std::priority_queue<int, vector<int>, greater<int>> small_pq;
typedef std::priority_queue<int, vector<int>, less<int>> big_pq;
template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}
void dbg_out() {}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  cerr << " " << H;
  if (sizeof...(T) > 0) cerr << " ,";
  dbg_out(T...);
}
void dbg_name(const string &s) {
  string ss = s;
  replace(ss.begin(), ss.end(), ',', ' ');
  cerr << "  ( " << ss << " )  ";
}
template <typename T>
inline void setmin(T &a, const T &b) {
  if (b < a) a = b;
}
template <typename T>
inline void setmax(T &a, const T &b) {
  if (b > a) a = b;
}
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
unordered_map<long long, int, custom_hash> safe_map;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rnd64(chrono::steady_clock::now().time_since_epoch().count());
const int MOD = 998244353;
int mul(int x, int y) { return 1ll * x * y % MOD; }
int add(int x, int y) { return ((x + y) % MOD + MOD) % MOD; }
int sub(int x, int y) { return ((x - y) % MOD + MOD) % MOD; }
int qpow(int a, int b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}
const int N = 1e4 + 5;
namespace Suffix {
int sa[N], rk[N * 2], oldrk[N * 2], cnt[N * 2], id[N], px[N * 2];
int ht[N];
bool cmp(int x, int y, int w) {
  return oldrk[x] == oldrk[y] && oldrk[x + w] == oldrk[y + w];
}
void suffix_array(char *s) {
  memset(cnt, 0, sizeof(cnt));
  memset(oldrk, 0, sizeof(oldrk));
  int n = strlen(s + 1);
  for (int i = 1; i <= n; i++) rk[i] = s[i];
  int m = 300;
  for (int i = 1; i <= n; i++) cnt[rk[i]]++;
  for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
  for (int i = n; i >= 1; i--) sa[cnt[rk[i]]--] = i;
  for (int w = 1; w < n; w <<= 1) {
    int p = 0;
    for (int i = n; i > n - w; i--) id[++p] = i;
    for (int i = 1; i <= n; i++)
      if (sa[i] > w) id[++p] = sa[i] - w;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++) cnt[px[i] = rk[id[i]]]++;
    for (int i = 1; i <= m; i++) cnt[i] += cnt[i - 1];
    for (int i = n; i >= 1; i--) sa[cnt[px[i]]--] = id[i];
    memcpy(oldrk, rk, sizeof(rk));
    p = 0;
    for (int i = 1; i <= n; i++) rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    m = p;
  }
  for (int i = 1, k = 0; i <= n; i++) {
    if (k) k--;
    while ((i + k <= n) && s[i + k] == s[sa[rk[i] - 1] + k]) k++;
    ht[rk[i]] = k;
  }
}
}  // namespace Suffix
const int M = 14;
char s[N];
int dp[N];
int f[N][M];
int calc(int i, int j) {
  int s = log2(j - i + 1);
  return min(f[i][s], f[j - (1 << s) + 1][s]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  using namespace Suffix;
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d %s", &n, s + 1);
    Suffix::suffix_array(s);
    for (int(i) = int(1); int(i) <= int(n); i++) {
      f[i][0] = Suffix::ht[i];
    }
    for (int(i) = int(1); int(i) <= int(M - 1); i++) {
      for (int(j) = int(1); int(j) <= int(n); j++) {
        f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
      }
    }
    int ans = 0;
    for (int(i) = int(1); int(i) <= int(n); i++) {
      dp[i] = n - i + 1;
      for (int(j) = int(1); int(j) <= int(i - 1); j++) {
        if (Suffix::rk[i] > Suffix::rk[j])
          dp[i] = max(dp[i], dp[j] + (n - i + 1) - calc(rk[j] + 1, rk[i]));
      }
      ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    fill(dp + 1, dp + 1 + n, 0);
    for (int(i) = int(0); int(i) <= int(M - 1); i++)
      for (int(j) = int(1); int(j) <= int(n); j++) f[j][i] = 0;
  }
  return 0;
}
