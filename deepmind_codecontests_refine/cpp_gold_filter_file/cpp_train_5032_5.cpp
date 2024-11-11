#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int k;
const int MAXN = 10;
const int MAXM = 100;
int a[MAXN][MAXM];
int b[MAXN][MAXM];
int c[MAXN][MAXM];
void _fill(void) {
  string dummy;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    cin >> dummy;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j] >> b[i][j] >> c[i][j];
    }
  }
}
struct dif {
  int diff;
  int canBuy;
};
bool operator<(const dif &A, const dif &B) { return A.diff < B.diff; }
int calc(int t1, int t2) {
  int result = 0;
  int space = k;
  dif A[MAXM];
  for (int j = 0; j < m; j++) {
    A[j].diff = b[t2][j] - a[t1][j];
    A[j].canBuy = c[t1][j];
  }
  sort(A, A + m);
  for (int i = m - 1; i >= 0 && space > 0; i--) {
    if (A[i].diff <= 0) break;
    int canTake = min(space, A[i].canBuy);
    result += canTake * A[i].diff;
    space -= canTake;
  }
  return result;
}
int main() {
  _fill();
  int result = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      result = max(result, calc(i, j));
    }
  }
  cout << result;
  return 0;
}
