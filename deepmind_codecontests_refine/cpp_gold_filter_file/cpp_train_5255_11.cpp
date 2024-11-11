#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const long long INF = 1e9 + 10;
const long long BINF = 1e18 + 10;
void source() {
  long long n, m;
  cin >> n >> m;
  vector<vector<long long>> a(n, vector<long long>(m));
  for (auto &it : a) {
    for (auto &it2 : it) {
      cin >> it2;
    }
  }
  long long mod = -1;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (a[i][0] == a[j][0]) {
        for (long long k = 1; k < m; k++) {
          if (a[i][k] != a[j][k]) {
            cout << "NO";
            exit(0);
          }
        }
      } else if (a[i][0] < a[j][0]) {
        for (long long k = 1; k < m; k++) {
          if (a[j][k] - a[i][k] == a[j][0] - a[i][0]) {
            continue;
          } else {
            long long cur = (a[j][0] - a[i][0]) - a[j][k] + a[i][k];
            if (cur <= 0) {
              cout << "NO";
              exit(0);
            }
            if (mod != -1 && cur != mod) {
              cout << "NO";
              exit(0);
            }
            mod = cur;
          }
        }
      }
    }
  }
  if (mod == -1) {
    mod = 1e18;
  }
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      if (mod <= a[i][j]) {
        cout << "NO";
        exit(0);
      }
    }
  }
  cout << "YES\n" << mod << '\n';
  for (long long i = 0; i < n; i++) {
    cout << a[i][0] << ' ';
  }
  cout << '\n';
  for (long long i = 0; i < m; i++) {
    if (a[0][0] > a[0][i]) {
      cout << a[0][i] + mod - a[0][0] << ' ';
    } else {
      cout << a[0][i] - a[0][0] << ' ';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}
