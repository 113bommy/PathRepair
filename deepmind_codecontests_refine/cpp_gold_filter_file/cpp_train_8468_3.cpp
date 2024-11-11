#include <bits/stdc++.h>
using namespace std;
const unsigned MAXN = 1010;
int A[MAXN][MAXN];
int R[MAXN], C[MAXN];
int n, m, k;
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> A[i][j];
  for (int i = 1; i <= n; i++) R[i] = i;
  for (int j = 1; j <= m; j++) C[j] = j;
  while (k--) {
    char t;
    int x, y;
    cin >> t >> x >> y;
    if (t == 'r') {
      int tmp = R[x];
      R[x] = R[y];
      R[y] = tmp;
    } else if (t == 'c') {
      int tmp = C[x];
      C[x] = C[y];
      C[y] = tmp;
    } else
      cout << A[R[x]][C[y]] << "\n";
  }
  return 0;
}
