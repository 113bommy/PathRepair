#include <bits/stdc++.h>
using namespace std;
int main() {
  int64_t t, a[200005], n;
  cin >> t;
  while (t--) {
    int64_t dem = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i < n; i++) {
      if (a[i] != a[i + 1]) dem++;
    }
    cout << dem << endl;
  }
}
