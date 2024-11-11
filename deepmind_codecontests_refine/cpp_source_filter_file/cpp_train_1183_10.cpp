#include <bits/stdc++.h>
using namespace std;
void count() {}
int main() {
  int n, k;
  cin >> n >> k;
  int a[n];
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (k > n) {
    cout << -1 << endl;
    return 0;
  }
  sort(a, a + n);
  cout << a[k - 1] << " " << a[k - 1] << endl;
  return 0;
}
