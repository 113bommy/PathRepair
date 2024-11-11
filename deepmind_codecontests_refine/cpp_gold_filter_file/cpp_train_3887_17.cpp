#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, s1 = 0, s2 = 0, cnt = 0;
  int a[100];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s1 += a[i];
  }
  sort(a, a + n);
  for (int i = n - 1; i >= 0; i--) {
    s1 -= a[i];
    s2 += a[i];
    cnt++;
    if (s2 > s1) break;
  }
  cout << cnt << endl;
  return 0;
}
