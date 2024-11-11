#include <bits/stdc++.h>
int dx[] = {-1, 0, 0, 1, -1, -1, 1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
using namespace std;
int n, m, k;
int arr[110][110];
int main() {
  n = ({
    int t;
    scanf("%d", &t);
    t;
  }),
  m = ({
    int t;
    scanf("%d", &t);
    t;
  }),
  k = ({
    int t;
    scanf("%d", &t);
    t;
  });
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      arr[i][j] = ({
        int t;
        scanf("%d", &t);
        t;
      });
  int ans = (int)1e9;
  if (n <= k) {
    for (int mask = 0; mask < (1 << n); mask++) {
      int res = 0;
      for (int i = 0; i < m; i++) {
        int c = 0;
        for (int j = 0; j < n; j++)
          if ((mask >> j & 1) ^ arr[j][i]) c++;
        res += min(n - c, c);
      }
      ans = min(ans, res);
    }
  } else {
    for (int a = 0; a < n; a++) {
      int temp[m];
      for (int i = 0; i < m; i++) temp[i] = arr[a][i];
      int res = 0;
      for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = 0; j < m; j++)
          if (temp[j] != arr[i][j]) c++;
        res += min(c, n - c);
      }
      ans = min(ans, res);
    }
  }
  if (ans <= k)
    cout << ans << "\n";
  else
    cout << "-1\n";
  return 0;
}
