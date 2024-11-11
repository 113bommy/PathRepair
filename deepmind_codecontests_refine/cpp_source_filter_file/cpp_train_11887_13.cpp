#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int n, x, a[200005], i, j;
  cin >> n;
  if (!(n % 2)) {
    cout << "NO";
    return 0;
  }
  cout << "YES"
       << "\n";
  for (i = 1; i <= n; i++) {
    if (!(i % 2)) {
      a[i] = 2 * i;
      a[n + i] = 2 + i - 1;
    } else {
      a[i] = 2 * i - 1;
      a[i + n] = 2 * i;
    }
  }
  for (i = 1; i <= 2 * n; i++) {
    cout << a[i] << " ";
  }
  return 0;
}
