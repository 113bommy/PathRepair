#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, c, ans(0);
  cin >> n >> c;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  int i = 0;
  while (i < n - 1) {
    int q = (a[i] - a[i + 1]) - c;
    ans = max(ans, q);
    i++;
  }
  cout << ans;
}
