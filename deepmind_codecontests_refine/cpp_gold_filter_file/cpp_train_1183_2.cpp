#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k > n) {
    cout << -1;
    return 0;
  }
  vector<int> cord;
  int kk;
  for (int i = 0; i < n; i++) cin >> kk, cord.push_back(kk);
  sort(cord.begin(), cord.end());
  cout << 0 << " " << cord[n - k] << endl;
  return 0;
}
