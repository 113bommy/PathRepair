#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[100001];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0, m = 0, f = 0, p = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      if (f == 1) {
        p += a[i];
        if (p == 0) {
          f = 0;
        } else {
          f = 1;
        }
        cnt = cnt;
      } else {
        cnt++;
      }
    } else {
      p += a[i];
      f = 1;
    }
  }
  cout << cnt << endl;
  return 0;
}
