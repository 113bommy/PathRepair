#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 1, 0, 0, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0, 0, 0};
const int inf = 1000000000;
const double eps = 0.000000009;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  string a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  long long ans = 7;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int diff = 0;
      for (int k = 0; k < 6; k++) {
        if (a[i][k] != a[j][k]) diff++;
      }
      ans = min(ans, (long long)ceil(diff / 2.0));
    }
  }
  cout << ans - 1 << endl;
  return 0;
}
