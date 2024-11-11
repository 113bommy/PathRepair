#include <bits/stdc++.h>
using namespace std;
const long long maxn = 100010;
const long long INF = 2147483647;
long long t, n, m, x, y, z, cnt[maxn];
int main() {
  ios::sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y >> z;
      cnt[y]++;
    }
    for (int i = 1; i <= n; i++) {
      if (cnt[i] == 0) {
        for (int j = 1; j <= n; j++) {
          if (j == i) continue;
          cout << j << " " << i << endl;
        }
        break;
      }
    }
  }
  return 0;
}
