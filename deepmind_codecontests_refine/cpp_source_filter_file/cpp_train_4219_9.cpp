#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[100];
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int s = 0, cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    s + a[i];
    cnt++;
    if (s >= m) break;
  }
  cout << cnt;
  return 0;
}
