#include <bits/stdc++.h>
using namespace std;
const int N = 101;
mt19937 rng(std::chrono::system_clock::now().time_since_epoch().count());
int n, x, y, ans[N], delta[N];
int find(int a) {
  int l = 2, r = 1000;
  while (l <= r) {
    int mid = (l + r) / 2;
    int temp = mid * (mid - 1) / 2;
    if (temp == a) return mid;
    if (temp < a)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return 0;
}
int main() {
  int nx, ny;
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i < n; i++) {
    cout << "+ " << i << endl;
    cin >> nx >> ny;
    delta[i] = ny - y;
    if (nx - x > 0) ans[i] = find(nx - x);
    x = nx;
    y = ny;
  }
  cout << "+ 1" << endl;
  cin >> nx >> ny;
  if (nx - x) ans[1] = find(nx - x) - 1;
  int temp = ny - y - delta[1] - 1;
  if (ans[2])
    ans[3] = temp - ans[2];
  else if (ans[3])
    ans[2] = temp - ans[3];
  else if (temp == 2)
    ans[2] = ans[3] = 1;
  else if (temp == 1 && delta[2])
    ans[3] = 1;
  else if (temp == 1)
    ans[2] = 1;
  for (int i = 4; i < n; i++) {
    if (ans[i]) continue;
    ans[i] = delta[i - 1] != (ans[i - 2] + 1) * (ans[i - 3] + 1);
  }
  ans[n] =
      (delta[n - 1] - (ans[n - 2] + 1) * (ans[n - 3] + 1)) / (ans[n - 2] + 1);
  cout << "! ";
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
}
