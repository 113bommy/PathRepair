#include <bits/stdc++.h>
using namespace std;
const int N = 55;
const int M = 1e9 + 7;
const double eps = 1e-6;
const double PI(acos(-1.0));
int n, k, m;
int d[N];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m >> k;
  for (int i = (1); i <= (m); i++) {
    cin >> d[i];
  }
  if (k > n - m) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = (1); i <= (n - 1); i++)
    if (d[i] > d[i + 1]) {
      k -= d[i] - d[i + 1];
    }
  if (k < 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << n << endl;
  for (int l = 1, r = 1, cur = 2, i = 1; i <= m; i++) {
    int tmp = min(k, min(r - l, d[i] - 1));
    k -= tmp;
    l = r - min(r - l, d[i] - 1) + tmp;
    if (d[i] < r - l + 1) {
      l += (r - l + 1) - d[i];
    }
    for (int j = 0; j < (d[i]); j++) {
      cout << l << " " << cur << endl;
      if (l < r) l++;
      cur++;
    }
    l = r + 1;
    r += d[i];
  }
}
