#include <bits/stdc++.h>
const int N = 1000010;
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);
  if (n < k) {
    cout << -1;
  } else {
    cout << a[n - 1] << " " << 0 << '\n';
  }
}
