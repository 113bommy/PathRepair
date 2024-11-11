#include <bits/stdc++.h>
using namespace std;
inline void setIO(string a) {}
struct e {
  int x, y;
} An[500005], Ann[500005];
int A[1005][1005];
int n, tot, Ans, Tot;
int main() {
  setIO("polygon");
  scanf("%d", &n);
  for (int i = 1; i <= n - 3; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    A[x][y] = 1;
  }
  for (int i = 2; i <= n; i++) {
    for (int j = n; j >= i + 2; j--)
      if (A[i][j]) An[++tot] = (e){i, j};
  }
  memcpy(Ann, An, sizeof(Ann));
  Tot = tot;
  Ans += tot;
  tot = 0;
  memset(A, 0, sizeof(A));
  for (int i = 1; i <= n - 3; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    A[x][y] = 1;
  }
  for (int i = 2; i <= n; i++)
    for (int j = n; j >= i; j--)
      if (A[i][j]) {
        int fail = 1;
        for (int k = j - 1; k >= i + 1; k--)
          if (A[i][k]) {
            An[++tot] = (e){1, k};
            fail = 0;
            break;
          }
        if (fail) {
          An[++tot] = (e){1, i + 1};
        }
      }
  Ans += tot;
  printf("%d\n", Ans);
  for (int i = 1; i <= Tot; i++) printf("%d %d\n", Ann[i].x, Ann[i].y);
  for (int i = tot; i >= 1; i--) printf("%d %d\n", An[i].x, An[i].y);
  return 0;
}
