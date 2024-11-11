#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = numeric_limits<long long>::max();
const long long NEGINF = numeric_limits<long long>::min();
template <typename T>
void print(T t) {
  cout << t << " ";
}
template <typename T, typename... Args>
void print(T t, Args... args) {
  cout << t << " ";
  print(args...);
}
template <class T>
void print(vector<T> &list) {
  for (auto &x : list) cout << x << " ";
}
template <class T>
void read(vector<T> &list, long long n) {
  list.clear(), list.resize(n);
  for (auto &x : list) cin >> x;
}
inline bool isPowerOfTwo(long long x) { return (x != 0 && (x & (x - 1)) == 0); }
long long len_of_number(long long n) {
  long long len(0);
  while (n != 0) {
    ++len;
    n /= 10;
  }
  return len;
}
long long sum_of_digits(long long n) {
  long long sod = 0;
  while (n != 0) {
    sod += (n % 10);
    n /= 10;
  }
  return sod;
}
bool isPalindrome(string str) {
  long long n = str.length();
  for (long long i = (0); i <= (n / 2); i++)
    if (str[i] != str[n - i - 1]) return false;
  return true;
}
long long fast_exp(long long x, long long i) {
  long long ans = 1;
  while (i > 0) {
    if (i & 1) ans = (ans * x);
    i >>= 1;
    x = (x * x);
  }
  return ans;
}
long long fast_exp(long long x, long long i, long long mod) {
  long long ans = 1;
  while (i > 0) {
    if (i & 1) ans = (ans * x) % mod;
    i >>= 1;
    x = (x * x) % mod;
  }
  return ans;
}
long long modInverse(long long x, long long mod) {
  return fast_exp(x, mod - 2, mod);
}
long long egcd_x, egcd_y, egcd_d;
void egcd(long long a, long long b) {
  if (b == 0) {
    egcd_x = 1, egcd_y = 0;
    egcd_d = a;
    return;
  }
  egcd(b, a % b);
  long long temp = egcd_x;
  egcd_x = egcd_y;
  egcd_y = temp - (a / b) * egcd_y;
}
long long extended_gcd(long long a, long long b) {
  if (a >= b) {
    egcd(a, b);
    return ((egcd_x % b) + b) % b;
  } else {
    egcd(b, a);
    return ((egcd_y % b) + b) % b;
  }
}
long long gcd(long long x, long long y) {
  long long t;
  while (y != 0) {
    t = x % y;
    x = y;
    y = t;
  }
  return x;
}
vector<long long> lp, pr;
void genPrimes(long long n) {
  lp.resize(n + 1, 0);
  long long size = 0;
  for (long long i = (2); i <= (n); i++) {
    if (!lp[i]) {
      lp[i] = i;
      pr.push_back(i);
      ++size;
    }
    for (long long j = 0; j < size && pr[j] <= lp[i] && (i * pr[j]) <= n; ++j)
      lp[i * pr[j]] = pr[j];
  }
}
bool isPrime(long long n) {
  long long root = sqrt(n);
  for (long long i = (2); i <= (root); i++)
    if (n % i == 0) return 0;
  return 1;
}
vector<long long> fact, invFact;
void genFact(long long n, long long M) {
  fact.resize(n + 1), invFact.resize(n + 1);
  fact[0] = fact[1] = invFact[0] = invFact[1] = 1;
  for (long long i = (2); i <= (n); i++) {
    fact[i] = (fact[i - 1] * i) % M;
    invFact[i] = modInverse(fact[i], M);
  }
}
long long ncr(long long n, long long r, long long M) {
  return (((fact[n] * invFact[n - r]) % M) * invFact[r] % M);
}
long long nc2(long long a) { return (a * (a - 1)) / 2; }
vector<long long> cnt;
string groupAndCnt(string str) {
  string a = "";
  long long prev_count = 0;
  char prev_char = '~';
  for (auto &c : str) {
    if (c != prev_char) {
      if (prev_count) {
        a += prev_char;
        cnt.push_back(prev_count);
      }
      prev_count = 1;
      prev_char = c;
    } else
      ++prev_count;
  }
  cnt.push_back(prev_count);
  a += prev_char;
  return a;
}
long long firstValEG(vector<long long>::iterator a,
                     vector<long long>::iterator b, long long c) {
  auto it = lower_bound(a, b, c);
  if (it == b) return -1;
  return it - a;
}
long long lastValEL(vector<long long>::iterator a,
                    vector<long long>::iterator b, long long c) {
  long long lo = 0, hi = distance(a, b) - 1, m;
  while (lo < hi) {
    m = (lo) + ((hi) - (lo) + 1) / 2;
    if (*(a + m) > c)
      hi = m - 1;
    else
      lo = m;
  }
  return ((*(a + lo)) <= c) ? lo : -1;
}
long long countInRange(vector<long long>::iterator a,
                       vector<long long>::iterator b, long long c,
                       long long d) {
  long long e = firstValEG(a, b, c);
  if (e == -1) return 0;
  return (e == -1) ? 0 : (lastValEL(a, b, d) - e + 1);
}
vector<long long> pset, pset_size;
void initSet(long long _size) {
  pset.resize(_size);
  pset_size.resize(_size);
  for (long long i = (0); i <= (_size - 1); i++) pset[i] = i, pset_size[i] = 1;
}
long long findSet(long long i) {
  return (pset[i] == i) ? i : (pset[i] = findSet(pset[i]));
}
void unionSet(long long i, long long j) {
  long long p1 = findSet(i);
  long long p2 = findSet(j);
  pset[p1] = p2;
  if (p1 != p2) {
    pset_size[p2] += pset_size[p1];
  }
}
bool isSameSet(long long i, long long j) { return findSet(i) == findSet(j); }
const long long MAXN = 1e5 + 10;
long long LOGN = 20;
long long SQRT = 320;
vector<vector<long long> > adjList;
long long adjList_size;
long long p2[] = {1,
                  2,
                  4,
                  8,
                  16,
                  32,
                  64,
                  128,
                  256,
                  512,
                  1024,
                  2048,
                  4096,
                  8192,
                  16384,
                  32768,
                  65536,
                  131072,
                  262144,
                  524288,
                  1048576,
                  2097152,
                  4194304,
                  8388608,
                  16777216,
                  33554432,
                  67108864,
                  134217728,
                  268435456,
                  536870912,
                  1073741824,
                  2147483648,
                  4294967296,
                  8589934592,
                  17179869184,
                  34359738368,
                  68719476736,
                  137438953472,
                  274877906944,
                  549755813888,
                  1099511627776,
                  2199023255552,
                  4398046511104,
                  8796093022208,
                  17592186044416,
                  35184372088832,
                  70368744177664,
                  140737488355328,
                  281474976710656,
                  562949953421312,
                  1125899906842624,
                  2251799813685248,
                  4503599627370496,
                  9007199254740992,
                  18014398509481984,
                  36028797018963968,
                  72057594037927936,
                  144115188075855872,
                  288230376151711744,
                  576460752303423488,
                  1152921504606846976};
class moQueries {
 public:
  long long l, r, qno;
  bool operator<(const moQueries &other) const {
    if (l / SQRT != other.l / SQRT) return l / SQRT < other.l / SQRT;
    return r < other.r;
  }
};
void getEdges(long long n, long long m, bool oneBased = true) {
  if (oneBased)
    adjList.resize(n + 1), adjList_size = n + 1;
  else
    adjList.resize(n), adjList_size = n;
  long long a, b;
  for (auto &x : adjList) x.clear();
  for (long long i = (1); i <= (m); i++) {
    cin >> a >> b;
    adjList[a].push_back(b), adjList[b].push_back(a);
  }
}
void printGraph(long long a, long long b, vector<vector<long long> > &graph) {
  for (long long i = (a); i <= (b); i++) {
    print(i, ": ");
    for (auto &x : graph[i]) {
      print(x, ",");
    }
    cout << "\n";
  }
}
vector<long long> tour, depth_tour;
long long tour_size;
vector<long long> depth, occ;
vector<vector<long long> > lookUp;
void rmq(long long n) {
  lookUp.clear();
  long long LOGN = log2(n) + 1;
  lookUp.resize(n);
  for (long long i = (0); i <= (n - 1); i++) lookUp[i].resize(LOGN);
  for (long long i = (0); i <= (n - 1); i++) lookUp[i][0] = i;
  for (long long j = 1; p2[j] <= n; j++) {
    for (long long i = 0; i <= n - (p2[j]); i++) {
      lookUp[i][j] = lookUp[i + (p2[j - 1])][j - 1];
      if (depth_tour[lookUp[i][j - 1]] <=
          depth_tour[lookUp[i + (p2[j - 1])][j - 1]])
        lookUp[i][j] = lookUp[i][j - 1];
    }
  }
}
inline long long minQuery(long long L, long long R) {
  long long j = (upper_bound(p2, p2 + 61, R - L + 1) - p2 - 1);
  return (depth_tour[lookUp[L][j]] <= depth_tour[lookUp[R - (p2[j]) + 1][j]])
             ? (lookUp[L][j])
             : (lookUp[R - (p2[j]) + 1][j]);
}
void dfs_tour(long long root, long long parent) {
  tour.push_back(root);
  depth_tour.push_back(depth[root]);
  occ[root] = tour_size++;
  for (auto &child : adjList[root]) {
    if (child != parent) {
      depth[child] = 1 + depth[root];
      dfs_tour(child, root);
      tour.push_back(root);
      depth_tour.push_back(depth[root]);
      occ[root] = tour_size++;
    }
  }
}
inline long long getLCA(long long u, long long v) {
  long long A = occ[u], B = occ[v];
  if (A > B) swap(A, B);
  return tour[minQuery(A, B)];
}
inline long long getDistance(long long u, long long v) {
  return depth[u] + depth[v] - 2 * depth[getLCA(u, v)];
}
void initLCA(long long root = 1) {
  long long n = adjList_size;
  tour.clear();
  depth_tour.clear();
  depth.resize(n);
  occ.resize(n);
  depth[root] = 0;
  tour_size = 0;
  dfs_tour(root, -1);
  rmq(tour_size);
}
vector<vector<long long> > parent;
vector<long long> subtreeSz;
void dfs(long long f = 1, long long g = 0) {
  subtreeSz[f] = 1;
  for (auto &s : adjList[f]) {
    if (s != g) {
      parent[s][0] = f;
      for (long long i = 1; i < LOGN; i++) {
        parent[s][i] = parent[parent[s][i - 1]][i - 1];
      }
      dfs(s, f);
      subtreeSz[f] += subtreeSz[s];
    }
  }
}
long long getParent(long long v, long long p) {
  if (p > depth[v]) return -1;
  for (long long i = 0; i < LOGN; i++) {
    if (p & (p2[i])) v = parent[v][i];
  }
  return v;
}
inline void solve(long long _T) {
  long long n;
  cin >> n;
  getEdges(n, n - 1);
  initLCA();
  parent.resize(n + 1);
  LOGN = log2(n) + 1;
  for (auto &x : parent) x.resize(LOGN);
  subtreeSz.resize(n + 1, 0);
  parent[1][0] = 0;
  dfs();
  long long q, a, b, d, X, Y, Z, ans;
  cin >> q;
  while (q--) {
    cin >> a;
    cin >> b;
    d = getDistance(a, b);
    if (d == 0) {
      cout << (n) << endl;
    } else if (d & 1) {
      cout << 0 << endl;
    } else {
      X = getLCA(a, b);
      ans = 0;
      if (depth[a] == depth[b]) {
        Y = getParent(a, (d >> 1) - 1);
        Z = getParent(b, (d >> 1) - 1);
        ans = n - (subtreeSz[Y] + subtreeSz[Z]);
      } else {
        if (depth[a] < depth[b]) swap(a, b);
        Y = getParent(a, (d >> 1));
        Z = getParent(a, (d >> 1) - 1);
        ans = subtreeSz[Y] - subtreeSz[Z];
      }
      cout << ans << endl;
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long test_cases;
  test_cases = 1;
  for (long long T = (0); T <= (test_cases - 1); T++) {
    solve(T);
  }
  return 0;
}
