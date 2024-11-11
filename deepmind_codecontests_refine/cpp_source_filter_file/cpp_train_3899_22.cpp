#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, v;
  cin >> n >> v;
  int a[3002] = {};
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x] = y;
  }
  int prev = 0;
  int sum = 0;
  for (int i = 1; i <= 3001; i++) {
    if (a[i] + prev <= v) {
      sum += a[i] + prev;
      prev = 0;
    } else {
      sum += v;
      prev = max(0, a[i] - max(0, v - prev));
    }
  }
  cout << sum << endl;
}
