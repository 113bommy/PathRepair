#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
int a[N], n;
int cal(int x) {
  int i = 1;
  int ans = 0;
  while (x) {
    int t = -x & x;
    while (i < t) ans |= i, i <<= 1;
    i <<= 1;
    x -= t;
  }
  return ans;
}
int main() {
  cin >> n;
  memset(a, -1, sizeof(a));
  for (int i = n; i; i--)
    if (a[i] == -1) {
      int k = cal(i);
      if (~a[i]) {
        a[i] = i;
      } else {
        a[i] = k;
        a[k] = i;
      }
    }
  if (a[0] < 0) a[0] = 0;
  int ret = 0;
  for (int i = 0; i <= n; i++) ret += a[i] | i;
  cout << ret << endl;
  for (int i = 0; i <= n; i++) printf("%d ", a[i]);
  return 0;
}
