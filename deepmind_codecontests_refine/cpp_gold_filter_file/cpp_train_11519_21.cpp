#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  long long ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    long long temp;
    cin >> temp;
    if (i % 2 == 0) ans = min(ans, temp);
  }
  if (n == 1) return cout << min(k * m, ans) << endl, 0;
  if (n % 2 == 0)
    return cout << "0" << endl, 0;
  else
    cout << min(ans, k * (m / ((n / 2) + 1))) << endl;
  return 0;
}
