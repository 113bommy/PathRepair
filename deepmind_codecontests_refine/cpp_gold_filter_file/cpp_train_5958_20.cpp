#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, g, b;
    cin >> n >> g >> b;
    long long int o = (n + 1) / 2;
    long long int m = o / g * (g + b);
    if (o % g == 0)
      m -= b;
    else
      m += (o % g);
    cout << (m > n ? m : n) << endl;
  }
  return 0;
}
