#include <bits/stdc++.h>
using namespace std;
int solve() {
  long long n;
  cin >> n;
  vector<int> a(n);
  for (int(i) = 0; (i) < n; (i)++) {
    cin >> a[i];
  }
  if (a[n - 1] == 15)
    cout << "DOWN";
  else if (a[n - 1] == 0)
    cout << "UP";
  else if (n == 1)
    cout << -1;
  else if (a[n - 1] > a[n])
    cout << "DOWN";
  else
    cout << "UP";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int ttt = 1;
  while (ttt--) {
    solve();
  }
  return 0;
}
