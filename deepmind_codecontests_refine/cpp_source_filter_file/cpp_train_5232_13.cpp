#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, n, a[3000], b[3000];
  cin >> t;
  while (t--) {
    long int s = 0, max = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
      int k = i;
      for (int j = 0; j < n; j++) {
        if (a[j] == b[k]) {
          k++;
          s++;
        }
      }
      if (s > max) max = s;
      s = 0;
    }
    cout << n - max << endl;
  }
  return 0;
}
