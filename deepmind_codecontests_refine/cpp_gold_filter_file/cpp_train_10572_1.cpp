#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
const int N = int(1e3) + 10;
int n, m;
int A[N][N], L[N][N], U[N][N], SQ[N][N];
short DP[10][10][N][N], P[N];
void pre() {
  P[1] = 0;
  for (int i = 2; i < N; i++) P[i] = P[i / 2] + 1;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
      for (int x = 1; x <= n; x++)
        for (int y = 1; y <= m; y++) {
          if (i == 0 && j == 0)
            DP[i][j][x][y] = SQ[x][y];
          else if (j == 0) {
            int sz = 1 << (i - 1);
            DP[i][j][x][y] = DP[i - 1][j][x][y];
            if (x > sz)
              DP[i][j][x][y] = max(DP[i][j][x][y], DP[i - 1][j][x - sz][y]);
          } else {
            int sz = 1 << (j - 1);
            DP[i][j][x][y] = DP[i][j - 1][x][y];
            if (y > sz)
              DP[i][j][x][y] = max(DP[i][j][x][y], DP[i][j - 1][x][y - sz]);
          }
        }
}
inline short query(int x1, int y1, int x2, int y2) {
  int l1 = P[x2 - x1 + 1];
  int l2 = P[y2 - y1 + 1];
  short ans1 = max(DP[l1][l2][x2][y2], DP[l1][l2][x1 + (1 << l1) - 1][y2]);
  short ans2 = max(DP[l1][l2][x2][y1 + (1 << l2) - 1],
                   DP[l1][l2][x1 + (1 << l1) - 1][y1 + (1 << l2) - 1]);
  return max(ans1, ans2);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> A[i][j];
      if (A[i][j]) {
        L[i][j] = L[i][j - 1] + 1;
        U[i][j] = U[i - 1][j] + 1;
        SQ[i][j] = min(SQ[i - 1][j - 1] + 1, min(L[i][j], U[i][j]));
      }
    }
  pre();
  int q;
  cin >> q;
  while (q--) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int l = 0, r = min(x2 - x1, y2 - y1) + 1;
    int ans = 0;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) {
        ans = max(ans, mid);
        l = mid + 1;
      } else
        r = mid - 1;
    }
    cout << ans << "\n";
  }
  return 0;
}
