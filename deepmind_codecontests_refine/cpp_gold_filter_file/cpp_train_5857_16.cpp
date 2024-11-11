#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, r;
    cin >> n >> r;
    long long a = min(n, r), ans = 0;
    if (r >= n) {
      a--;
      cout << (a * (a + 1)) / 2 + (1) << endl;
    } else {
      cout << (a * (a + 1)) / 2 << endl;
    }
  }
}
