#include <bits/stdc++.h>
using namespace std;
int a[100000];
int main() {
  int n, j, x;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    j = min(i, n - 1 - i);
    x = x - j;
    if (x > 0) {
      a[x]++;
    }
  }
  int maxx = 0;
  for (int i = 0; i < 100000; i++) {
    maxx = max(maxx, a[i]);
  }
  if (n == 1) {
    cout << 0;
  } else
    cout << n - maxx;
}
