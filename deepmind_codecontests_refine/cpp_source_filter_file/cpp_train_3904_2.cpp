#include <bits/stdc++.h>
using namespace std;
long long maxi = LLONG_MIN;
long long mini = LLONG_MAX;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
long long t, i, j, k, n, temp, flag, ans, m;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  if (k == 0) {
    cout << "NO\n";
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    if (x >= 3 && x <= n - 2 && y >= 3 && y <= m - 2) {
    } else {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
  return 0;
}
