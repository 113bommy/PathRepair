#include <bits/stdc++.h>
using namespace std;
long long int l, r;
vector<long long int> ans;
int k;
long long int solve() {
  long long int res = l;
  ans.push_back(l);
  int diff = r - l + 1;
  for (int i = 1; i < 1 << diff; i++) {
    if (__builtin_popcount(i) <= k) {
      long long int _xor = 0;
      vector<long long int> tmp;
      for (int j = 0; j < diff; j++)
        if ((i >> j) & 1) {
          _xor ^= l + j;
          tmp.push_back(l + j);
        }
      if (_xor < res) {
        res = _xor;
        ans = tmp;
      }
    }
  }
  return res;
}
int main() {
  cin >> l >> r >> k;
  k = min(k, 4);
  if (k == 1 || r == l) {
    cout << l << "\n1\n" << l << endl;
    return 0;
  }
  if (r - l <= 6) {
    long long int val = solve();
    cout << val << "\n";
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
  }
  if (k == 3) {
    long long int x = 3;
    while (x <= r) {
      long long int y = x - 1;
      long long int z = (x / 3) * 2 - 1;
      if (z >= l && x <= r) {
        cout << "0\n3\n" << x << " " << y << " " << z << " " << endl;
        return 0;
      }
      x *= 2;
    }
    k = 2;
  }
  if (k == 2) {
    cout << "1\n2\n" << (l + 1) / 2 * 2 << " " << (l + 1) / 2 * 2 + 1 << "\n";
    return 0;
  }
  if (k == 4) {
    printf("0\n4\n");
    for (int i = 0; i < 4; i++) cout << (l + 3) / 4 * 4 + i << " ";
    cout << "\n";
  }
  return 0;
}
