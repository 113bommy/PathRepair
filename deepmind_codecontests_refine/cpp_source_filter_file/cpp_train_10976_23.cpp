#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  long long n, k, x, z, sum = 0;
  cin >> n >> k;
  z = n - k;
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x <= z) sum++;
  }
  cout << sum / 3 << endl;
  return 0;
}
