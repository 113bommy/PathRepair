#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
pair<int, int> a[N];
int main() {
  int n, d;
  cin >> n >> d;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a, a + n);
  long long L, R, maj, ans;
  ;
  L = R = ans = maj = 0;
  while (R < n) {
    if (a[R].first - a[L].first < d) {
      maj += a[R].second;
      ans = max(maj, ans);
      R++;
    } else {
      maj -= a[L].second;
      L++;
      ans = max(ans, maj);
    }
  }
  cout << ans << endl;
}
