#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000020;
const int K = 60;
const int MOd = 1e9 + 7;
int a, ar[3][maxn], q;
void solve(int n) {
  scanf("%d %d", &a, &q);
  int num = 0;
  for (int i = 1, x, y; i <= q; i++) {
    scanf("%d %d", &x, &y);
    x--;
    if (ar[x][y] == 1) {
      num -= ar[!x][y - 1];
      num -= ar[!x][y];
      num -= ar[!x][y + 1];
    } else {
      num += ar[!x][y - 1];
      num += ar[!x][y];
      num += ar[!x][y + 1];
    }
    ar[x][y] ^= 1;
    if (num)
      printf("No\n");
    else
      printf("Yes\n");
  }
}
int main() {
  int n = 1;
  for (int i = 1; i <= n; i++) solve(i);
  return 0;
}
