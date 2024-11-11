#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e+5 + 10;
const int INF = 2e+9;
const double e = 1e-8;
int t[2000];
int m[2000];
int h[2000];
bool u[2000];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  char c;
  int cnt[2000];
  for (int i = 0; i < m; i++) {
    cnt[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> c;
      if (c == 'U') {
        if (i % 2 == 0) {
          cnt[j]++;
        }
      }
      if (c == 'R') {
        if ((i + j) < m) {
          cnt[i + j]++;
        }
      }
      if (c == 'L') {
        if ((j - i) >= 0) {
          cnt[j - i]++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << cnt[i] << " ";
  }
  return 0;
}
