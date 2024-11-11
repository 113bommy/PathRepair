#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, s = 0, c = 0;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      s = s + a[i];
      if (a[i] == 0) {
        c++;
      }
    }
    if (s == 0 && c == 0)
      cout << 1 << endl;
    else if (s + c == 0)
      cout << c + 1 << endl;
    else
      cout << c << endl;
  }
}
