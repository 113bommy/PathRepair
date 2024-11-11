#include <bits/stdc++.h>
using namespace std;
const int mx = 1e5 + 10;
int main() {
  int n, a[101], i, sum = 0;
  cin >> n;
  for (i = 0; i < n; i++) cin >> a[i];
  sort(a, a + n + 1);
  for (i = 1; i < n; i += 2) {
    sum += a[i] - a[i - 1];
  }
  cout << sum << endl;
  return 0;
}
