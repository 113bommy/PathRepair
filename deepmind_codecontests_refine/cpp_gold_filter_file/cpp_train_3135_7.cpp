#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void input(T &x) {
  register char c = getchar();
  x = 0;
  int neg = 0;
  for (; ((c < 48 || c > 57) && c != '-'); c = getchar())
    ;
  if (c == '-') {
    neg = 1;
    c = getchar();
  }
  for (; c > 47 && c < 58; c = getchar()) {
    x = (x << 1) + (x << 3) + c - 48;
  }
  if (neg) x = -x;
}
inline long long bigmod(long long p, long long e, long long M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return ret;
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) {
  return bigmod(a, M - 2, M);
}
const int N = 1001;
vector<int> G[N];
int link[N], second[N], T[N], rig[N];
bool dfs(int u) {
  second[u] = 1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (T[v]) continue;
    T[v] = 1;
    if (link[v] == -1 || dfs(link[v])) {
      link[v] = u;
      rig[u] = v;
      return 1;
    }
  }
  return 0;
}
int maxMatching(int n) {
  int ret = 0;
  memset(link, -1, sizeof link);
  memset(rig, -1, sizeof rig);
  for (int i = 1; i <= n; i++) {
    memset(second, 0, sizeof second);
    memset(T, 0, sizeof T);
    if (dfs(i)) ret++;
  }
  return ret;
}
int dir[100][2];
int ways = 0;
void buildGraph(int n, int m) {
  for (int i = 1; i < N; i++) G[i].clear();
  for (int k = 1; k <= n; k++) {
    for (int l = 1; l <= m; l++) {
      if ((k + l) % 2 == 0) {
        for (int p = 0; p < ways; p++) {
          int x = k + dir[p][0], y = l + dir[p][1];
          if (x >= 1 && x <= n && y >= 1 && y <= m) {
            int vi = k * m + l, vj = x * m + y;
            G[vi].push_back(vj);
          }
        }
      }
    }
  }
}
int main() {
  for (int i = -3; i <= 3; i++) {
    for (int j = -3; j <= 3; j++) {
      if (abs(i) + abs(j) == 3) dir[ways][0] = i, dir[ways][1] = j, ways++;
    }
  }
  int Ans[15][24];
  for (int i = 1; i <= 10; i++) {
    for (int j = i; j <= 20; j++) {
      buildGraph(i, j);
      Ans[i][j] = maxMatching(i * j + j) * 2;
    }
  }
  long long n, m;
  input(n), input(m);
  if (n > m) swap(n, m);
  if (n == 1) {
    if (m <= 20)
      cout << Ans[n][m] << endl;
    else if (m % 6 && m % 6 <= 3)
      cout << (m / 6 * 6) << endl;
    else if (m % 6 == 0)
      cout << m << endl;
    else if (m % 6 == 5)
      cout << m - 1 << endl;
    else if (m % 5 == 4)
      cout << m - 2 << endl;
  } else if (n == 2) {
    if (m <= 20)
      cout << Ans[n][m] << endl;
    else
      cout << 2 * m << endl;
  } else {
    if (n % 2 && m % 2)
      cout << (n * m - 1) << endl;
    else
      cout << n * m << endl;
  }
  return 0;
}
