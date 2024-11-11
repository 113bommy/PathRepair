#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    pair<long long int, long long int> p1, p2;
    long long int a1 = a[1];
    p1.first = a[1];
    p1.second = 1;
    bool k = false;
    for (int i = 1; i <= n; i++) {
      if (a1 != a[i]) {
        p2.first = a[i];
        p2.second = i;
        k = true;
        break;
      }
    }
    if (k) {
      cout << "YES\n";
      for (int i = 2; i <= n; i++) {
        if (a[i] != p1.first) {
          cout << p1.second << " " << i << endl;
        }
        if (a[i] != p2.first) {
          cout << p2.second << " " << i << endl;
        }
      }
    } else {
      cout << "NO\n";
    }
  }
}
