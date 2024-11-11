#include <bits/stdc++.h>
using namespace std;
int main() {
  char a[55][55], b[55][55];
  int i, j, n1, m1, n2, m2, mx = -1, mxx = 0, myy = 0;
  cin >> n1 >> m1;
  for (i = 1; i <= n1; i++)
    for (j = 1; j <= m1; j++) cin >> a[i][j];
  cin >> n2 >> m2;
  for (i = 1; i <= n2; i++)
    for (j = 1; j <= m2; j++) cin >> b[i][j];
  for (int x = -55; x <= 55; x++)
    for (int y = -55; y <= 55; y++) {
      int res = 0;
      for (i = 1; i <= n1; i++)
        for (j = 1; j <= m1; j++) {
          if (i + x > 0 && i + x <= n2)
            if (j + y > 0 && j + y <= m2)
              if (a[i][j] == '1' && b[i + x][j + y] == '1') res++;
        }
      if (res > mx) {
        mx = res;
        mxx = x;
        myy = y;
      }
    }
  cout << mxx << ' ' << myy;
  return 0;
}
