#include <bits/stdc++.h>
using namespace std;
const int MAXINT = (int)2e5 + 10;
int p1[MAXINT], p2[MAXINT];
char c[MAXINT];
void fast() {
  cin.tie(0);
  cin.sync_with_stdio(0);
}
int main() {
  fast();
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    p1[i] = p1[i - 1];
    p2[i] = p2[i - 1];
    cin >> c[i];
    if (c[i] == 'a')
      p1[i]++;
    else
      p2[i]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (k || c[i] == 'a') {
      int l = i, r = n + 1, mid;
      while (r > l + 1) {
        mid = (r + l) / 2;
        if ((p2[mid] - p2[i - 1]) <= k)
          l = mid;
        else
          r = mid - 1;
      }
      ans = max(ans, l - i + 1);
    }
    if (k || c[i] == 'b') {
      int l = i, r = n + 1, mid;
      while (r - l > 1) {
        mid = (r + l) / 2;
        if ((p1[mid] - p1[i - 1]) <= k)
          l = mid;
        else
          r = mid - 1;
      }
      ans = max(ans, l - i + 1);
    }
  }
  cout << ans;
  return 0;
}
