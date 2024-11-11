#include <bits/stdc++.h>
using namespace std;
static const double EPS = 1e-5;
int x[1000], y[1000];
int n, m;
long long ans = 0;
char a[1000][1000];
int main() {
  cin >> n >> m;
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      cin >> a[j][i];
      if (a[j][i] == '*') {
        y[j]++;
        x[i]++;
      }
    }
  }
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      if (a[j][i] == '*') ans += (y[j] - 1) * (x[i] - 1);
    }
  }
  cout << ans << endl;
}
