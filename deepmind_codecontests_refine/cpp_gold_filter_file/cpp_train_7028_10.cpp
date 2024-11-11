#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, ans = 1, t;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  int l = 0, r = n - 1;
  while (l < n && v[l] == 0) l++;
  while (r > -1 && v[r] == 0) r--;
  if (l > r) {
    cout << 0;
    return 0;
  }
  t = 0;
  for (; l <= r; l++) {
    if (v[l] == 0)
      t++;
    else {
      ans *= (t + 1);
      t = 0;
    }
  }
  cout << ans;
}
