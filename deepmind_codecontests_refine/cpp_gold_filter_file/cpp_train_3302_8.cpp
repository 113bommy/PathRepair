#include <bits/stdc++.h>
using namespace std;
int k[200010], a[200010];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int x = a[i] / n;
    if (a[i] % n > i) {
      k[i] = x * n + n + i;
    } else
      k[i] = x * n + i;
  }
  int res = -1, minn = 2100000000;
  for (int i = 0; i < n; i++) {
    if (k[i] != -1) {
      if (k[i] < minn) {
        minn = k[i];
        res = i;
      }
    }
  }
  cout << res + 1;
}
