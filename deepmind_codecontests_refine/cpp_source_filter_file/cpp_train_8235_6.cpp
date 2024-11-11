#include <bits/stdc++.h>
using namespace std;
const int N = 205;
struct Node {
  int a, b, c, d, e, f;
  Node() {}
  Node(int _a, int _b, int _c, int _d, int _e, int _f) {
    a = _a, b = _b, c = _c, d = _d, e = _e, f = _f;
  }
};
Node dp[N][N][5][5];
bool vi[N][N][5][5];
void upd(int a, int b, int c, int d, int e, int f) {
  if (a + e > 200 || b + f > 200) return;
  int aa = a + e, bb = b + f, cc = c + (e > f), dd = d + (e < f);
  vi[aa][bb][cc][dd] = true;
  dp[aa][bb][cc][dd] = Node(a, b, c, d, e, f);
}
void print(int a, int b, int c, int d) {
  if (c + d == 0) return;
  auto x = dp[a][b][c][d];
  print(x.a, x.b, x.c, x.d);
  printf("%d:%d ", x.e, x.f);
}
int main(int argc, const char *argv[]) {
  int T;
  cin >> T;
  memset(vi, false, sizeof(vi));
  vi[0][0][0][0] = true;
  for (int a = 0; a <= 200; a++) {
    for (int b = 0; b <= 200; b++) {
      for (int c = 0; c <= 3; c++) {
        for (int d = 0; d <= 3; d++) {
          if (vi[a][b][c][d]) {
            if (c + d > 5) continue;
            if (c == 3 || d == 3) continue;
            int n = (c + d) <= 4 ? 25 : 15;
            for (int va = 0; va <= n - 3; va++) upd(a, b, c, d, va, n);
            for (int vb = 0; vb <= n - 3; vb++) upd(a, b, c, d, n, vb);
            for (int va = n; va <= 200; va++) upd(a, b, c, d, va, va - 2);
            for (int vb = n; vb <= 200; vb++) upd(a, b, c, d, vb - 2, vb);
          }
        }
      }
    }
  }
  while (T--) {
    int a, b;
    scanf("%d%d", &a, &b);
    int diff = -5, ans1 = -1, ans2;
    for (int i = 0; i <= 3; i++) {
      for (int j = 0; j <= 3; j++)
        if (vi[a][b][i][j]) {
          if (i <= 2 && j <= 2) continue;
          if (i + j > 5) continue;
          if (i - j > diff) {
            diff = i - j;
            ans1 = i, ans2 = j;
          }
        }
    }
    if (ans1 == -1)
      puts("Impossible");
    else {
      cout << ans1 << " " << ans2 << endl;
      print(a, b, ans1, ans2);
      puts("");
    }
  }
  return 0;
}
