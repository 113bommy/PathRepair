#include <bits/stdc++.h>
using namespace std;
long long F[60][2][2], k;
int n, str[60];
long long DFS(int p, int x, int y) {
  long long &ans = F[p][x][y];
  if (p * 2 - 1 > n) ans = 1;
  if (ans != -1) return ans;
  ans = 0;
  for (int i = 0; i < 2; i++)
    if (str[p] == i || str[p] == -1)
      for (int j = 0; j < 2; j++)
        if (str[n - p + 1] == j || str[n - p + 1] == -1)
          if (p * 2 - 1 != n || i == j)
            if (x || i <= j)
              if (y || i + j <= 1)
                ans += DFS(p + 1, x || i < j, y || i + j == 0);
  return ans;
}
int main() {
  memset(F, -1, sizeof(F));
  memset(str, -1, sizeof(str));
  cin >> n >> k;
  if (DFS(1, 0, 0) <= k) {
    printf("-1\n");
    return 0;
  }
  str[1] = 0;
  for (int i = 2; i <= n; i++) {
    memset(F, -1, sizeof(F));
    str[i] = 0;
    long long temp = DFS(1, 0, 0);
    if (temp <= k) k -= temp, str[i] = 1;
  }
  for (int i = 1; i <= n; i++) printf("%d", str[i]);
  printf("\n");
  return 0;
}
