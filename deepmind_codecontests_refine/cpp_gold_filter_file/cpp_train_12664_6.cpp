#include <bits/stdc++.h>
using namespace std;
long long arr[500000];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout << fixed << setprecision(10);
  int q;
  cin >> q;
  int n = 0, i = 0;
  long long sum = 0;
  double ans = 0;
  for (int qi = 0; qi < q; qi++) {
    int ty;
    cin >> ty;
    if (ty == 1) {
      cin >> arr[n];
      n++;
      while (i + 1 < n) {
        if ((sum + arr[n - 1]) >= (i + 1) * arr[i]) {
          sum += arr[i];
          i++;
        } else {
          break;
        }
      }
      ans = max(ans, arr[n - 1] - (sum + arr[n - 1]) / (i + 1.));
    } else {
      cout << ans << '\n';
    }
  }
  return 0;
}
