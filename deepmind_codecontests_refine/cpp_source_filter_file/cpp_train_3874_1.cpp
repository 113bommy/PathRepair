#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E3 + 7;
int a[MAXN];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n = 3;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int cnt = a[2] - a[1];
    if (cnt <= a[0]) {
      cout << floor((a[0] - cnt) / 2) + a[2] << endl;
    } else {
      cout << a[0] + a[1] << endl;
    }
  }
  return 0;
}
