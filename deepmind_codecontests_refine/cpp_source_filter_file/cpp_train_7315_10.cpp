#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      b[i] = a[i];
    }
    int c = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] < a[i + 1]) {
        c++;
      }
    }
    if (c == n - 1)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
  return 0;
}
