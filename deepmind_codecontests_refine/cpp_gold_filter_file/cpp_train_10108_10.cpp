#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 7;
const int N = 1e6 + 10;
const int M = 20;
int L[N], R[N], val[N], op[N];
int p[N][M];
int muda[N][M];
void dfs(int u, int last) {
  p[u][0] = last;
  if (L[u]) dfs(L[u], u);
  if (R[u]) dfs(R[u], u);
  switch (op[u]) {
    case 0:
      val[u] = val[L[u]] & val[R[u]];
      if (val[u] == 0) {
        if (val[L[u]] | val[R[u]]) {
          if (!val[L[u]]) muda[L[u]][0] = 1;
          if (!val[R[u]]) muda[R[u]][0] = 1;
        }
      } else {
        muda[L[u]][0] = 1;
        muda[R[u]][0] = 1;
      }
      break;
    case 1:
      val[u] = val[L[u]] | val[R[u]];
      if (val[u] == 0) {
        muda[L[u]][0] = 1;
        muda[R[u]][0] = 1;
      } else if (val[L[u]] == 0) {
        muda[R[u]][0] = 1;
      } else if (val[R[u]] == 0) {
        muda[L[u]][0] = 1;
      }
      break;
    case 2:
      val[u] = val[L[u]] ^ val[R[u]];
      muda[L[u]][0] = 1;
      muda[R[u]][0] = 1;
      break;
    case 3:
      val[u] = !val[L[u]];
      muda[L[u]][0] = 1;
      break;
    case 4:
      break;
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string o;
    cin >> o;
    if (o == "AND") {
      op[i] = 0;
      cin >> L[i] >> R[i];
    } else if (o == "IN") {
      op[i] = 4;
      cin >> val[i];
    } else if (o == "XOR") {
      op[i] = 2;
      cin >> L[i] >> R[i];
    } else if (o == "OR") {
      op[i] = 1;
      cin >> L[i] >> R[i];
    } else if (o == "NOT") {
      op[i] = 3;
      cin >> L[i];
    }
  }
  muda[1][0] = 1;
  dfs(1, 1);
  for (int j = 1; j < M; j++) {
    for (int i = 1; i <= n; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
      muda[i][j] = (muda[i][j - 1] & muda[p[i][j - 1]][j - 1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (op[i] != 4) continue;
    if (muda[i][M - 1])
      printf("%d", !val[1]);
    else
      printf("%d", val[1]);
  }
  puts("");
}
