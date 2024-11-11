#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, cnt = 0;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  for (int i = 0; i < n; i += 2) {
    cnt += (a[i + 1] - a[i]);
  }
  cout << cnt;
  return 0;
}
