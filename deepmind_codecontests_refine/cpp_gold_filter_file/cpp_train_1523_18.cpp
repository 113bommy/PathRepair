#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const long long infLL = 9000000000000000000;
inline bool checkBit(long long n, int i) { return n & (1LL << i); }
inline long long setBit(long long n, int i) {
  return n | (1LL << i);
  ;
}
inline long long resetBit(long long n, int i) { return n & (~(1LL << i)); }
int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
inline bool isLeapYear(long long year) {
  return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
inline void normal(long long &a) {
  a %= 1000000007;
  (a < 0) && (a += 1000000007);
}
inline long long modMul(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a * b) % 1000000007;
}
inline long long modAdd(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  return (a + b) % 1000000007;
}
inline long long modSub(long long a, long long b) {
  a %= 1000000007, b %= 1000000007;
  normal(a), normal(b);
  a -= b;
  normal(a);
  return a;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, 1000000007 - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
const int maxn = 5010;
int vis[maxn], store[maxn], x[maxn], y[maxn], par[maxn], n, cc;
vector<int> adjList[maxn];
int findSet(int x) {
  if (x != par[x]) return par[x] = findSet(par[x]);
  return x;
}
bool oka(int val) {
  memset(vis, 0, sizeof(vis));
  memset(store, 0, sizeof(store));
  cc = 0;
  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;
    ++cc;
    vis[i] = true;
    queue<int> bfs;
    bfs.push(i);
    while (!bfs.empty()) {
      int u = bfs.front();
      bfs.pop();
      for (int v = 0; v < n; ++v) {
        if (abs(x[v] - x[u]) + abs(y[v] - y[u]) <= val) continue;
        if (vis[v]) {
          if (store[u] == store[v]) return false;
        } else {
          vis[v] = true;
          store[v] = 1 - store[u];
          bfs.push(v);
        }
      }
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
  int low = 0, high = 1e4 + 100;
  while (low < high) {
    int mid = (low + high) / 2;
    if (oka(mid))
      high = mid;
    else
      low = mid + 1;
  }
  oka(low);
  ;
  cout << low << '\n' << modPow(2, cc);
  return 0;
}
