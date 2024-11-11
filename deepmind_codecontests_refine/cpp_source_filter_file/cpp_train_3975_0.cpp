#include <bits/stdc++.h>
using namespace std;
const int maxN = 50 + 5;
const int maxS = 100 + 5;
int n, m, k;
int dp[maxN][maxN][maxS];
struct node {
  long long a, b;
  int c, id;
  node() {}
  node(long long a, long long b, int c, int id) : a(a), b(b), c(c), id(id) {}
  inline bool operator<(const node &sec) const { return c < sec.c; }
};
vector<node> Q;
inline long long median(long long a, long long b, long long c) {
  if (a >= min(b, c) && a <= max(b, c)) return a;
  if (b >= min(a, c) && b <= max(a, c)) return b;
  return c;
}
inline void print(int x, int y, int z) {
  dp[x][y][z] -= (Q[x].a + z);
  if (dp[x][y][z] == 0) {
    cout << "YES" << endl;
    cout << Q[x].id << ' ' << Q[x].a + z << endl;
    return;
  }
  long long val = Q[x].a + z;
  for (int f = 0; f < x; f++)
    if (Q[f].c < Q[x].c) {
      if (val % k == 0 && median(val / k, Q[f].a, Q[f].b) == val / k)
        if (dp[f][y - 1][val / k - Q[f].a] == dp[x][y][z]) {
          print(f, y - 1, val / k - Q[f].a);
          break;
        }
      if (median(val - k, Q[f].a, Q[f].b) == val - k)
        if (dp[f][y - 1][val - k - Q[f].a] == dp[x][y][z]) {
          print(f, y - 1, val - k - Q[f].a);
          break;
        }
    }
  cout << Q[x].id << ' ' << Q[x].a + z << endl;
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= m; i++) {
    node tmp;
    cin >> tmp.a >> tmp.b >> tmp.c;
    tmp.id = i;
    Q.push_back(tmp);
  }
  sort(Q.begin(), Q.end());
  for (int i = 0; i < m; i++) {
    node now = Q[i];
    for (int j = 1; j <= n; j++) {
      for (long long diff = now.b - now.a; diff >= 0; diff--) {
        long long val = now.a + diff;
        for (int z = 0; z < i; z++)
          if (Q[z].c < Q[i].c) {
            if (val % k == 0 && median(val / k, Q[z].a, Q[z].b) == val / k)
              dp[i][j][diff] =
                  max(dp[i][j][diff], dp[z][j - 1][val / k - Q[z].a]);
            if (median(val - k, Q[z].a, Q[z].b) == val - k)
              dp[i][j][diff] =
                  max(dp[i][j][diff], dp[z][j - 1][val - k - Q[z].a]);
          }
        if (dp[i][j][diff] > 0) dp[i][j][diff] += now.a + diff;
        if (j == 1) dp[i][j][diff] = now.a + diff;
      }
    }
  }
  long long res = 0;
  int x = 0, y = 0, z = 0;
  for (int i = 0; i < m; i++)
    for (long long diff = Q[i].b - Q[i].a; diff >= 0; diff--)
      if (dp[i][n][diff] > res) {
        res = dp[i][n][diff];
        x = i, y = n, z = diff;
      }
  if (res != 0ll)
    print(x, y, z);
  else
    cout << "NO" << endl;
  return 0;
}
