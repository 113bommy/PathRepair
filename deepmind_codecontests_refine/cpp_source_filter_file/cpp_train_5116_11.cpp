#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, h;
  cin >> n >> h;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++) {
    sort(a, a + i + 1);
    int sum = 0;
    for (int j = i; j >= 0; j -= 2) {
      sum += a[j];
    }
    if (sum <= h) {
      res = i + 1;
    }
  }
  cout << res << "\n";
  return 0;
}
