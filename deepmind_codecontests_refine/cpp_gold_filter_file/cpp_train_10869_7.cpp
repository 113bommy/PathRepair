#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int main() {
  {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed;
    cout << setprecision(10);
  }
  int i, j, n, min = 0;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  min = abs(a[0] - a[1]);
  int p1 = 1;
  int p2 = 2;
  for (i = 1; i < n - 1; i++) {
    if (abs(a[i] - a[i + 1]) < min) {
      min = abs(a[i] - a[i + 1]);
      p1 = i + 1;
      p2 = i + 2;
    }
  }
  if (abs(a[n - 1] - a[0]) < min)
    cout << 1 << " " << n;
  else
    cout << p1 << " " << p2;
}
