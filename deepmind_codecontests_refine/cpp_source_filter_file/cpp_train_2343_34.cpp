#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e6 + 200;
long long int n, a[maxN], s, b[maxN], mx, mn = maxN;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    ("%d", &a[i]);
    mx = max(a[i], mx);
    mn = min(a[i], mn);
    b[a[i]]++;
  }
  for (int i = mn; i <= mx; i++) {
    if (b[i] > 0) {
      b[i + 1] += b[i] / 2;
      s += b[i] % 2;
    }
  }
  while (b[mx + 1] > 0) {
    s += b[mx + 1] % 2;
    b[mx + 1] /= 2;
  }
  cout << s;
  return 0;
}
