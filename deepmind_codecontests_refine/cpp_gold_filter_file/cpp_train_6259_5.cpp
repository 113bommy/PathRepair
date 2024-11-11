#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) continue;
    int pos = lower_bound(a + 1, a + n + 1, 2 * a[i]) - a;
    if (a[pos - 1] > a[i]) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
