#include <bits/stdc++.h>
using namespace std;
const int MAX_SZ = 1e6 + 2;
const int MOD = 1e9 + 7;
int t = 1, n, m, q, ql, qr;
char ch;
vector<vector<int> > mat, ans;
vector<int> apref;
int solve() {
  int p1, p2;
  for (int i = 1; i < n + 1; ++i) {
    p1 = -1, p2 = -1;
    for (int j = 0; j < n; ++j) {
      if (apref[j] <= i) {
        p1 = apref[j];
        break;
      }
    }
    for (int j = 0; j < n; ++j) {
      if (apref[j] <= i && apref[j] != p1) {
        p2 = apref[j];
        break;
      }
    }
    for (int j = 1; j < n + 1; ++j) {
      if (p1 != -1 && p1 != j)
        ans[i - 1][j - 1] = p1;
      else if (p2 != -1 && p2 != j)
        ans[i - 1][j - 1] = p2;
      else
        ans[i - 1][j - 1] = -1;
    }
  };
  for (auto r : ans) {
    for (auto e : r) {
      ;
    };
  };
  for (int j = 0; j < n; ++j) {
    p1 = -1;
    for (int i = 0; i < n; ++i) {
      if (p1 == -1)
        p1 = ans[i][j];
      else {
        for (int k = 0; k < n; ++k) {
          if (mat[j][k] == p1) {
            p2 = p1;
            break;
          }
          if (mat[j][k] == ans[i][j]) {
            p2 = ans[i][j];
            break;
          }
        }
        p1 = p2;
      }
    }
    printf("%d ", p1);
  }
  printf("\n");
  return 0;
}
int main() {
  while (t--) {
    scanf("%d", &n);
    mat.resize(n, vector<int>(n));
    ans.resize(n, vector<int>(n));
    apref.resize(n);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        scanf("%d", &mat[i][j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      scanf("%d", &apref[i]);
    }
    solve();
  }
}
