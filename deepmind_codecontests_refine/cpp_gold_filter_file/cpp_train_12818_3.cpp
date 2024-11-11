#include <bits/stdc++.h>
using namespace std;
int a[100005], n, x, y, cnt;
int main() {
  cin >> n >> x >> y;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] <= x) cnt++;
  }
  if (x > y)
    cout << n;
  else
    cout << (cnt + 1) / 2;
  return 0;
}
