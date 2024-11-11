#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, ans;
  int count = 0;
  int a[105];
  cin >> n >> x >> y;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i] <= x) count++;
  }
  if (x > y)
    cout << n;
  else {
    if (count % 2 == 0)
      cout << count / 2;
    else
      cout << count / 2 + 1;
  }
}
