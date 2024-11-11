#include <bits/stdc++.h>
const long long int INF = 1e9, MOD = 1e9 + 7, MAXN = 15485864;
const long double EPS = 0.000001;
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long int n, m, k, x, s, a[200002], b[200002], c[200002], d[200002];
  cin >> n >> m >> k;
  cin >> x >> s;
  for (int i = 0; i < m; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }
  for (int i = 0; i < k; i++) {
    cin >> d[i];
  }
  long long int time = n * x;
  for (int i = 0; i < m; i++) {
    if (d[i] <= s) {
      time = min(time, (n - c[i]) * x);
    }
  }
  for (int i = 0; i < m; i++) {
    if (b[i] > s) continue;
    long long int l = upper_bound(d, d + k, s - b[i]) - d;
    l--;
    if (l < 0) {
      time = min(time, n * a[i]);
    } else
      time = min(time, (n - c[l]) * a[i]);
  }
  cout << time;
  return 0;
}
