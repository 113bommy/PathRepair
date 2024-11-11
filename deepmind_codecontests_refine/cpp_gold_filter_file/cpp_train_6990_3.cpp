#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 6;
const long long inf = 1e9;
int n, m, k;
int a[N][N];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  int x = 12;
  while (x--) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      int flag1 = 0;
      for (int j = 1; j <= m; j++) {
        if (a[i][j] & 1) flag1++;
      }
      if (flag1 == m)
        sum++;
      else if (flag1 != 0) {
        puts("TAK");
        sum = 0;
        for (int k = 1; k <= n; k++)
          if (k != i)
            if (a[k][1] & 1) sum++;
        sum %= 2;
        for (int j = 1; j <= m; j++)
          if ((sum & 1) && a[i][j] % 2 == 0) {
            sum = j;
            break;
          } else if ((sum % 2 == 0) && a[i][j] % 2 == 1) {
            sum = j;
            break;
          }
        for (int k = 1; k <= n; k++) printf("%d ", (k == i) ? sum : 1);
        return 0;
      }
    }
    if (sum & 1) {
      puts("TAK");
      for (int i = 1; i <= n; i++) printf("1 ");
      return 0;
    }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] >>= 1;
  }
  puts("NIE");
}
