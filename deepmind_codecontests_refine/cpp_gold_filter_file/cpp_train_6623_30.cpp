#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k, x;
  int t = 0;
  cin >> n >> k >> x;
  int kk = n - k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (kk > 0) {
      t += a[i];
    }
    kk--;
  }
  t += k * x;
  cout << t;
  return 0;
}
