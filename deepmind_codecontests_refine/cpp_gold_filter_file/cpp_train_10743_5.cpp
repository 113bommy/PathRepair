#include <bits/stdc++.h>
using namespace std;
void run() {
  int n;
  cin >> n;
  ;
  int m;
  cin >> m;
  ;
  int a[n];
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  sort(a, a + n);
  if (n == 2) {
    cout << "-1\n";
  } else if (m < n) {
    cout << "-1\n";
  } else {
    m -= n;
    cout << accumulate(a, a + n, 0ll) * 2 + m * (a[0] + a[1]) << "\n";
    for (int i = 1; i < n; i++) {
      cout << i << " " << i + 1 << "\n";
    }
    cout << 1 << " " << n << "\n";
    while (m--) {
      cout << a[0] << " " << a[1] << "\n";
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    run();
  }
  return 0;
}
