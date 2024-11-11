#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, a, b;
    cin >> n >> a >> b;
    for (long long i = 0; i < n; i++) {
      cout << char('b' + i % b);
    }
    cout << endl;
  }
}
