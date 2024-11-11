#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, s, Max, dist;
int nr[5005], v[5005], d[5005];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    ++nr[a];
    dist = b - a;
    if (dist <= 0) dist += n;
    if (v[a] > dist || v[a] == 0) v[a] = dist;
    d[a] = (nr[a] - 1) * n + v[a];
  }
  for (int i = 1; i <= n; ++i) {
    Max = 0;
    for (int j = 0; j < n; ++j) {
      s = i + j;
      if (s > n) s -= n;
      if (d[s] && d[s] + j > Max) Max = d[s] + j;
    }
    cout << Max << ' ';
  }
  return 0;
}
