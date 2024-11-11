#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0;
  char ch = getchar();
  bool positive = 1;
  for (; ch < '0' || ch > '9'; ch = getchar())
    if (ch == '-') positive = 0;
  for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
  return positive ? x : -x;
}
inline char RC() {
  char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
inline long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
inline long long lcm(long long a, long long b, long long MOD) {
  return a / gcd(a, b) * b % MOD;
}
inline long long Sub(long long x, long long y, long long mod) {
  long long res = x - y;
  while (res < 0) res += mod;
  return res;
}
inline long long Add(long long x, long long y, long long mod) {
  long long res = x + y;
  while (res >= mod) res -= mod;
  return res;
}
inline long long POW_MOD(long long x, long long y, long long mod) {
  long long ret = 1;
  while (y > 0) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
const int N = 100000 + 50;
const int inf = 2100000000;
const long long INF = 1LL << 60;
const double PI = 3.14159265358;
int n, m;
vector<int> e[N];
unordered_set<long long> mp;
int dfs(int u) {
  vector<int> adj;
  queue<int> unPairs;
  for (int v : e[u]) {
    long long id = min((long long)v * N + u, (long long)u * N + v);
    if (mp.find(id) == mp.end()) {
      adj.push_back(v);
      mp.insert(id);
    }
  }
  for (int v : adj) {
    int w = dfs(v);
    if (w)
      printf("%d %d %d\n", u, v, w);
    else
      unPairs.push(v);
  }
  while (unPairs.size() >= 2) {
    int v = unPairs.front();
    unPairs.pop();
    int w = unPairs.front();
    unPairs.pop();
    printf("%d %d %d\n", v, u, w);
  }
  if (unPairs.size()) {
    return unPairs.front();
  } else {
    return 0;
  }
}
int main() {
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
    cnt++;
  }
  if (cnt & 1)
    cout << "No solution" << endl;
  else
    dfs(1);
  return 0;
}
