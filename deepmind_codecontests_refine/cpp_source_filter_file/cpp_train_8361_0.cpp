#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, u = 0, v = 0;
  int f[1001][1001] = {{0}, {0}};
  int l[1001][1001] = {{0}, {0}};
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int d, c;
    cin >> c >> d;
    f[c][d]++;
    f[0][d]++;
  }
  for (int i = 1; i <= n; i++) {
    int d, c;
    cin >> c >> d;
    l[c][d]++;
    l[0][d]++;
  }
  for (int i = 1; i <= 1000; i++) {
    u += min(f[0][i], l[0][i]);
    for (int j = 1; j <= 1000; j++) v += min(f[j][i], l[j][i]);
  }
  cout << u << " " << v;
}
