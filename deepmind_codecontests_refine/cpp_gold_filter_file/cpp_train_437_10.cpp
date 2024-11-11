#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, m, x;
  cin >> t;
  while (t--) {
    cin >> n;
    int ar[100000], c = 1;
    for (int i = 0; i < n; i++) cin >> ar[i];
    sort(ar, ar + n);
    for (int i = 0; i < n - 1; i++) {
      if (ar[i] != ar[i + 1]) c++;
    }
    cout << c << endl;
  }
}
