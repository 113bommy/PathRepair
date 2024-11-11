#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int INF = 1e9;
const int N = 1e5 + 7;
int pos[N];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x, y;
    cin >> x >> y;
    int ans = 0;
    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        if (pos[j] < i - y || y == 0) ++ans;
        pos[j] = i;
        if (j * j != x) {
          if (pos[x / j] < i - y || y == 0) ++ans;
          pos[x / j] = i;
        }
      }
    }
    cout << ans << endl;
  }
}
