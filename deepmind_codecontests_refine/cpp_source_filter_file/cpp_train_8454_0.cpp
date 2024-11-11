#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    int sum = 0;
    int zer = 0;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] == 0) zer++;
      sum += a[i];
    }
    if (sum && zer) {
      cout << 0 << endl;
      continue;
    }
    if (zer) {
      if (sum + zer)
        cout << zer << endl;
      else
        cout << zer + 1 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
