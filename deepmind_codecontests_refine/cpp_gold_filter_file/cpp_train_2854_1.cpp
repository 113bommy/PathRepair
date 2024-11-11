#include <bits/stdc++.h>
using namespace std;
int a[100007];
int main() {
  int n, kq;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  kq = 2;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n - 2; ++i) {
    int j = 0;
    for (j = i + 2; j <= n; ++j)
      if (a[j] != a[j - 1] + a[j - 2]) break;
    kq = max(kq, j - i);
    i = j - 2;
  }
  cout << kq;
  return 0;
}
