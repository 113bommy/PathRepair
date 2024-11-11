#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18L;
constexpr int mod = int(1e9) + 7;
long long t = 1, n, m, k;
void solve() {
  cin >> n >> m >> k;
  vector<vector<char>> ar(n, vector<char>(m, '0'));
  if (n % 2) {
    for (int i = 0; i < m and k > 0; i += 2) {
      ar[0][i] = ar[0][i + 1] = '1';
      k--;
    }
    for (int i = 0; i < m; i++) {
      if (ar[0][i] != '1') {
        cout << "nO"
             << "\n";
        return;
      }
    }
  }
  if (k % 2) {
    cout << "nO"
         << "\n";
    return;
  }
  for (int i = n % 2; i + 1 < n and k > 1; i += 2) {
    for (int j = 0; j + 1 < m and k > 1; j += 2) {
      ar[i][j] = ar[i + 1][j] = ar[i][j + 1] = ar[i + 1][j + 1] = '1';
      k -= 2;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ar[i][j] == '0' and !((i + 1 < n and ar[i + 1][j] == '0') or
                                (i - 1 >= 0 and ar[i - 1][j] == '0'))) {
        cout << "nO"
             << "\n";
        return;
      }
    }
  }
  if (k) {
    cout << "nO"
         << "\n";
    return;
  }
  cout << "yEs"
       << "\n";
  vector<vector<char>> ans(n, vector<char>(m, '0'));
  vector<vector<int>> direction(n, vector<int>(m, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (direction[i][j] == 0) {
        if (ar[i][j] == '1') {
          direction[i][j] = 1;
          direction[i][j + 1] = 2;
        } else {
          direction[i][j] = 3;
          direction[i + 1][j] = 4;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (ans[i][j] == '0') {
        char a = 'a';
        if (direction[i][j] == 1) {
          bool flag = true;
          while (flag) {
            if (j - 1 >= 0 and ans[i][j - 1] == a) {
              a++;
              continue;
            }
            if (i - 1 >= 0 and ans[i - 1][j] == a) {
              a++;
              continue;
            }
            if (j + 2 < m and ans[i][j + 2] == a) {
              a++;
              continue;
            }
            flag = false;
          }
          ans[i][j] = ans[i][j + 1] = a;
        } else if (direction[i][j] == 3) {
          bool flag = true;
          while (flag) {
            if (j - 1 >= 0 and ans[i][j - 1] == a) {
              a++;
              continue;
            }
            if (i - 1 >= 0 and ans[i - 1][j] == a) {
              a++;
              continue;
            }
            flag = false;
          }
          ans[i][j] = ans[i + 1][j] = a;
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << ans[i][j];
    }
    cout << "\n";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> t;
  while (t--) solve();
  return 0;
}
