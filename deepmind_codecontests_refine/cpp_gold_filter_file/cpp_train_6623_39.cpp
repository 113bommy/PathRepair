#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, x;
  cin >> n >> k >> x;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a, a + n);
  int s = 0;
  for (int i = 0; i < n - k; ++i) {
    s += a[i];
  }
  s += k * x;
  cout << s << endl;
  return 0;
}
