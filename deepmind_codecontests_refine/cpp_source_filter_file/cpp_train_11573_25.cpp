#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500004;
const int MOD = 1000003;
char *dd[MAXN];
int a1[MAXN], b1[MAXN];
int n, m;
void solve() {
  long long ret = 1;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    dd[i] = new char[m + 1];
    scanf("%s", dd[i]);
  }
  memset(a1, -1, sizeof(a1));
  memset(b1, -1, sizeof(b1));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char a;
      a = dd[i][j];
      if (a == '.')
        continue;
      else {
        int x, y;
        a -= '0';
        if (a == 1 || a == 2) {
          y = ((!(a & 1)) + j) % 2;
          x = j % 2;
        } else {
          x = (1 + j) % 2;
          y = ((a & 1) + i) % 2;
        }
        if (a1[i] == -1) {
          a1[i] = x;
        } else if (a1[i] != x)
          ret = 0;
        if (b1[j] == -1) {
          b1[j] = y;
        } else if (b1[j] != y)
          ret = 0;
      }
    }
  if (ret != 0) {
    for (int i = 0; i < m; i++)
      if (a1[i] == -1) ret = (ret * 2) % MOD;
    for (int i = 0; i < n; i++)
      if (b1[i] == -1) ret = (ret * 2) % MOD;
  }
  cout << ret << endl;
}
int main() {
  while (scanf("%d %d", &n, &m) != EOF) {
    solve();
  }
  return 0;
}
