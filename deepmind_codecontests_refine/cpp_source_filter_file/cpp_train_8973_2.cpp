#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int b[2 * 100005];
  int h[2 * 100005];
  int *id = b + 100005;
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++) cin >> h[i];
    memset(b, -1, sizeof(b));
    int sum = 0;
    id[0] = 2 * n;
    for (int i = 2 * n - 1; i >= n; i--) {
      if (h[i] == 1)
        sum--;
      else
        sum++;
      id[sum] = i;
    }
    sum = 0;
    int mn = 2 * n;
    for (int i = 0; i < n; i++) {
      if (h[i] == 1)
        sum--;
      else
        sum++;
      if (id[-sum] != -1) mn = min(mn, id[-sum] - (i + 1));
    }
    cout << mn << '\n';
  }
  return 0;
}
