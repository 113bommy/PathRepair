#include <bits/stdc++.h>
using namespace std;
int arr[1001], n, s, ans[30][30];
int main() {
  cin >> n;
  for (int i = 0; i < n * n; i++) {
    cin >> s;
    arr[s]++;
  }
  if (n % 2 == 0) {
    for (int i = 0; i <= 1000; i++)
      if (arr[i] % 4 != 0) {
        cout << "NO" << endl;
        return 0;
      }
  }
  if (n % 2 == 1) {
    int duo = (n / 2) * 4, kk = 0, pp = 0;
    int si = (n / 2) * (n / 2);
    int y = 0, t = 0;
    for (int i = 0; i <= 1000; i++) {
      if (arr[i] % 2 != 0) {
        y++;
      }
      if (arr[i] == 2 || arr[i] == 3) kk++;
      if (arr[i] >= 4) {
        pp += (arr[i] / 4);
      }
    }
    if (y != 1 || (kk == duo && kk != 0) || pp < si) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  if (n % 2 == 1) {
    for (int i = 1; i <= 1000; i++) {
      if (arr[i] % 2 != 0) {
        ans[n / 2 + 1][n / 2 + 1] = i;
        arr[i] -= 1;
        break;
      }
    }
  }
  for (int i = 1; i <= n / 2; i++) {
    for (int j = 1; j <= n / 2; j++) {
      for (int d = 1; d <= 1000; d++) {
        if (arr[d] >= 4) {
          arr[d] -= 4;
          ans[i][j] = ans[n - i + 1][j] = ans[i][n - j + 1] =
              ans[n - i + 1][n - j + 1] = d;
          break;
        }
      }
    }
  }
  if (n % 2 == 1) {
    for (int r = 1; r <= n / 2; r++)
      for (int i = 1; i <= 1000; i++) {
        if (arr[i] != 0) {
          ans[n / 2 + 1][r] = ans[n / 2 + 1][n - r + 1] = i;
          arr[i] -= 2;
          break;
        }
      }
    for (int r = 1; r <= n / 2; r++)
      for (int i = 1; i <= 1000; i++) {
        if (arr[i] != 0) {
          ans[r][n / 2 + 1] = ans[n - r + 1][n / 2 + 1] = i;
          arr[i] -= 2;
          break;
        }
      }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
