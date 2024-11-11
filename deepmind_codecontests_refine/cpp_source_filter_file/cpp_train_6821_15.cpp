#include <bits/stdc++.h>
struct cc {
  int first;
  int second;
  int third;
};
using namespace std;
int r[5000];
int c[5000];
int u[5000][5000];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  int m;
  cin >> m;
  int k;
  cin >> k;
  cc a[k];
  for (int i = 0; i <= k - 1; i++) {
    cin >> a[i].first;
    cin >> a[i].second;
    a[i].second--;
    cin >> a[i].third;
  }
  for (int i = k - 1; i >= 0; i--) {
    if (a[i].first == 1) {
      if (r[a[i].second] == 0) {
        r[a[i].second] = 1;
        for (int j = 0; j <= n - 1; j++) {
          if (u[a[i].second][j] == 0) u[a[i].second][j] = a[i].third;
        }
      }
    } else {
      if (c[a[i].second] == 0) {
        c[a[i].second] = 1;
        for (int j = 0; j <= n - 1; j++) {
          if (u[j][a[i].second] == 0) u[j][a[i].second] = a[i].third;
        }
      }
    }
  }
  for (int i = 0; i <= n - 1; i++) {
    for (int j = 0; j <= m - 1; j++) {
      cout << u[i][j] << ' ';
    }
    cout << endl;
  }
}
