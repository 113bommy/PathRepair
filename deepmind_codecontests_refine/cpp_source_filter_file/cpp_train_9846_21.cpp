#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int a[N];
int abso(int x) { return x < 0 ? -x : x; }
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = 2e9;
  int mini = *max_element(a, a + n);
  for (int i = mini; i <= N; ++i) {
    int res = 0;
    for (int j = 0; j < n; ++j) {
      res += a[j] < i ? i - a[j] : 0;
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
  return 0;
}
