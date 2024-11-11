#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, x;
    cin >> n >> x;
    long long a[n], i;
    for (i = 0; i < n; i++) cin >> a[i];
    bool hash[501];
    memset(hash, false, sizeof(hash));
    for (i = 0; i < n; i++) hash[a[i]] = true;
    long long v = 0;
    for (i = 1; i <= 101; i++) {
      if (hash[i] == true)
        v++;
      else {
        if (x > 0) {
          hash[i] = true;
          x--;
          v++;
        } else
          break;
      }
    }
    cout << v << endl;
  }
  return 0;
}
