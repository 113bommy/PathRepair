#include <bits/stdc++.h>
using namespace std;
long long int a[105], b[105];
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i, count;
    cin >> n;
    for (i = 1; i <= n; i++) {
      cin >> a[i] >> b[i];
    }
    count = 0;
    for (i = 1; i <= n; i++)
      if (a[i] >= a[i - 1] && b[i] >= b[i - 1] &&
          a[i] - a[i - 1] >= b[i] - b[i - 1]) {
        continue;
      } else {
        count = 1;
      }
    if (count)
      cout << "NO" << endl;
    else
      cout << "YES" << endl;
  }
  return 0;
}
