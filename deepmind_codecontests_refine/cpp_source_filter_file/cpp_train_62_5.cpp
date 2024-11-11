#include <bits/stdc++.h>
using namespace std;
long long n, d, c, flag, minn, maxx, minn2, sum, ans, flag1, a[11010];
int main() {
  flag1 = 1;
  cin >> n >> d;
  for (int i = (0); i < (n); i++) {
    cin >> a[i];
    sum += a[i];
    minn = min(minn, sum);
    maxx = max(maxx, sum);
    if (a[i] == 0) {
      if ((maxx - sum) > d || (flag1 && sum < 0)) {
        ans++;
        minn = 0;
        maxx = 0;
        sum = 0;
        flag1 = 0;
      }
    }
  }
  sum = 0;
  for (int i = 0; i < n && (!flag); i++) {
    sum += a[i];
    if (!a[i] && sum < 0) sum = 0;
    if (sum > d) {
      flag = 1;
    }
  }
  if (flag == 1) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
