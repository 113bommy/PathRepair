#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    long long a = 1;
    for (int i = 3; i <= n * 2; i++) {
      a = a * i % 1000000007;
    }
    cout << a << endl;
  }
  return 0;
}
