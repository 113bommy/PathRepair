#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
int n, m;
int a[107][107];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - 'A';
    }
  }
  bool kek = true;
  bool lol = true;
  if (n % 3 == 0) {
    int x = n / 3;
    set<int> val;
    for (int t = 0; t < 3; t++) {
      int sh = a[t * x][0];
      val.insert(sh);
      for (int j = t * x; j < t * x + x; j++) {
        for (int k = 0; k < m; k++) {
          if (a[j][k] != sh) {
            kek = false;
          }
        }
      }
    }
    if (val.size() != 3) {
      kek = false;
    }
  } else {
    kek = false;
  }
  if (m % 3 == 0) {
    int x = m / 3;
    set<int> val;
    for (int t = 0; t < 3; t++) {
      int sh = a[0][t * x];
      val.insert(sh);
      for (int j = t * x; j < t * x + x; j++) {
        for (int k = 0; k < n; k++) {
          if (a[k][j] != sh) {
            lol = false;
          }
        }
      }
    }
    if (val.size() != 3) {
      lol = false;
    }
  } else {
    lol = false;
  }
  cout << (kek || lol ? "YES\n" : "NO\n");
  return 0;
}
