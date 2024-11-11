#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  long long int n, m, num, num1, ans = 0, cnt = 1;
  cin >> n >> m;
  cin >> num1;
  for (int i = 0; i < n - 1; ++i) {
    cin >> num;
    if (num == num1) {
      ans = max(ans, cnt);
      cnt = 1;
    } else
      ++cnt;
    ans = max(ans, cnt);
    num1 = num;
  }
  cout << ans << '\n';
}
