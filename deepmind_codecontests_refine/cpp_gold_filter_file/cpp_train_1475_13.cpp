#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int cnt = 0, x = 0;
  for (int i = 0; i < n; ++i) {
    x++;
    while (i < n) {
      if (a[i] >= x) {
        cnt++;
        break;
      } else
        i++;
    }
  }
  cout << cnt << endl;
  return 0;
}
