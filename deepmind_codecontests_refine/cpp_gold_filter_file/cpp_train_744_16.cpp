#include <bits/stdc++.h>
using namespace std;
static const int MAXN = 200;
int a[MAXN + 10];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0), cout.tie(0);
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
      cout << "YES" << endl;
      continue;
    }
    if (a[1] == 1 && !((a[2] == n && a[n] == 2) || (a[2] == 2 && a[n] == n))) {
      cout << "NO" << endl;
      continue;
    }
    if (a[1] == n &&
        !((a[2] == n - 1 && a[n] == 1) || (a[n] == n - 1 && a[2] == 1))) {
      cout << "NO" << endl;
      continue;
    }
    if (a[1] != 1 && a[1] != n &&
        !((a[2] == a[1] - 1 && a[n] == a[1] + 1) ||
          (a[2] == a[1] + 1 && a[n] == a[1] - 1))) {
      cout << "NO" << endl;
      continue;
    }
    if (a[n] == 1 &&
        !((a[1] == n && a[n - 1] == 2) || (a[1] == 2 && a[n - 1] == n))) {
      cout << "NO" << endl;
      continue;
    }
    if (a[n] == n && !((a[1] == 1 && a[n - 1] == n - 1) ||
                       (a[1] == n - 1 && a[n - 1] == 1))) {
      cout << "NO" << endl;
      continue;
    }
    bool flag = true;
    for (int i = 2; i <= n - 1; i++) {
      if (a[i] == 1 && !((a[i - 1] == n && a[i + 1] == 2) ||
                         (a[i - 1] == 2 && a[i + 1] == n))) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
      if (a[i] == n && !((a[i - 1] == 1 && a[i + 1] == n - 1) ||
                         (a[i - 1] == n - 1 && a[i + 1] == 1))) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
      if (a[i] != 1 && a[i] != n &&
          !((a[i - 1] == a[i] + 1 && a[i + 1] == a[i] - 1) ||
            (a[i - 1] == a[i] - 1 && a[i + 1] == a[i] + 1))) {
        cout << "NO" << endl;
        flag = false;
        break;
      }
    }
    if (flag) cout << "YES" << endl;
  }
  return 0;
}
