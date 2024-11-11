#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << "0" << endl;
    return 0;
  }
  sort(a, a + 2 * n);
  long long miner = LLONG_MAX;
  for (int i = 1; i < n; i++) {
    miner = (a[i + n - 1] - a[i] < miner) ? a[i + n - 1] - a[i] : miner;
  }
  long long ans1 = miner * (a[2 * n - 1] - a[0]);
  long long ans2 = (a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
  cout << ((ans1 < ans2) ? ans1 : ans2) << endl;
  return 0;
}
