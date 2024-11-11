#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, a[100005], c[100005];
  cin >> t;
  for (int x = 0; x < t; x++) cin >> a[x];
  c[t - 1] = 0;
  int flag = a[t - 1];
  for (int x = t - 2; x >= 0; x--) {
    a[x] >= flag ? c[x] = 0 : c[x] = flag - a[x] + 1;
    flag = max(flag, a[x]);
  }
  for (int x = 0; x < t; x++) cout << c[x] << " ";
  return 0;
}
