#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a, b;
    long long int c = 0, d = 0;
    bool f = true;
    for (long long int i = 0; i < n; i++) {
      cin >> a >> b;
      if (a < c || b < d || a - c < b - d) f = false;
      c = a, d = b;
    }
    if (f)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
