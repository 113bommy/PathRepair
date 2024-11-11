#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[] = {1, -1, 0, 0, -1, 1, 1, -1};
template <class T>
inline T biton(T n, T pos) {
  return n | ((T)1 << pos);
}
template <class T>
inline T bitoff(T n, T pos) {
  return n & ~((T)1 << pos);
}
template <class T>
inline T ison(T n, T pos) {
  return (bool)(n & ((T)1 << pos));
}
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <typename T>
string NumberToString(T Number) {
  ostringstream second;
  second << Number;
  return second.str();
}
inline int nxt() {
  int aaa;
  scanf("%d", &aaa);
  return aaa;
}
inline long long int lxt() {
  long long int aaa;
  scanf("%lld", &aaa);
  return aaa;
}
inline double dxt() {
  double aaa;
  scanf("%lf", &aaa);
  return aaa;
}
template <class T>
inline T bigmod(T p, T e, T m) {
  T ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % m;
    p = (p * p) % m;
  }
  return (T)ret;
}
int ar[200010];
int dp[200010][22][2];
vector<int> adj[200010];
long long int bit[22] = {0};
void dfs(int u, int p = -1) {
  for (int i = 0; i <= 20; i++)
    dp[u][i][ison(ar[u], i)]++, bit[i] += ison(ar[u], i);
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == p) continue;
    dfs(v, u);
    for (int j = 0; j <= 20; j++) {
      bit[j] += (dp[u][j][0] * dp[v][j][1] * 1LL);
      bit[j] += (dp[u][j][1] * dp[v][j][0] * 1LL);
      for (int k = 0; k < 2; k++) {
        dp[u][j][k] += dp[v][j][k ^ (ison(ar[u], j))];
      }
    }
  }
}
int main() {
  int n = nxt();
  for (int i = 1; i <= n; i++) {
    ar[i] = nxt();
  }
  for (int i = 1; i < n; i++) {
    int a = nxt();
    int b = nxt();
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  long long int res = 0;
  for (int i = 0; i <= 20; i++) {
    res += bit[i] * (1LL << i);
  }
  cout << res << endl;
  return 0;
}
