#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, a[1000000];
  int i;
  int p = 1;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a + n);
    for (i = 0; i < n - 1; i++) {
      if (a[i] != a[i + 1]) p++;
    }
    cout << p << endl;
    p = 1;
  }
}
