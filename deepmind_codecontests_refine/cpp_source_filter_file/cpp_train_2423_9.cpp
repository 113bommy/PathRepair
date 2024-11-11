#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n;
    for (int i = 0; i < n / 2; i++) {
      cin >> a >> b;
      cout << -b << " " << a;
    }
    cout << endl;
  }
}
