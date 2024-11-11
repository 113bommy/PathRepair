#include <bits/stdc++.h>
using namespace std;
long long sum;
long long n, m, mx, mn;
long long mins[100009], maxs[100009];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> mins[i];
    mx = max(mx, mins[i]);
  }
  mn = 999999999;
  for (int i = 1; i <= m; i++) {
    cin >> maxs[i];
    mn = min(mn, maxs[i]);
  }
  if (mn < mx) {
    cout << -1 << "\n";
    return 0;
  }
  sort(mins + 1, mins + n + 1);
  sort(maxs + 1, maxs + m + 1);
  if (mn == mx) {
    for (int i = 1; i <= m; i++) {
      sum += maxs[i];
    }
    for (int i = 1; i < n; i++) {
      sum += (m * mins[i]);
    }
  }
  if (mx < mn) {
    if (n == 1 || m == 1) {
      cout << -1 << "\n";
      return 0;
    }
    for (int i = 1; i <= m; i++) {
      sum += maxs[i];
    }
    for (int i = 1; i < n; i++) {
      sum += (m * mins[i]);
    }
    sum += mins[n];
    sum -= mins[n - 1];
  }
  cout << sum << "\n";
}
