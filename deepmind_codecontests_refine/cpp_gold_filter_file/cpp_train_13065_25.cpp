#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  char x, y;
  int kq = 0;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      cin >> x >> y;
      if (x == '1' || y == '1') kq++;
    }
  printf("%d", kq);
}
