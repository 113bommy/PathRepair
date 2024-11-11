#include <bits/stdc++.h>
using namespace std;
int a[2 * 100002];
int main() {
  int n;
  cin >> n;
  int cnt = 0;
  if (n & 1 == 0) {
    cout << "NO" << endl;
  } else {
    printf("YES\n");
    for (int i = 1; i <= n; ++i) {
      if (i & 1) {
        a[i] = ++cnt;
        a[i + n] = ++cnt;
      } else {
        a[i + n] = ++cnt;
        a[i] = ++cnt;
      }
    }
    for (int i = 1; i <= 2 * n; ++i) cout << a[i] << " ";
  }
  return 0;
}
