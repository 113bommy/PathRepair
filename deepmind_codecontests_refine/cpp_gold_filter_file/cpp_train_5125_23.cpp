#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, d, a[1000];
  cin >> t;
  while (t--) {
    cin >> n >> d;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    while (d--) {
      for (int i = 1; i < n; i++) {
        if (a[i] > 0) {
          a[i]--;
          a[i - 1]++;
          break;
        }
      }
    }
    cout << a[0] << endl;
  }
  return 0;
}
