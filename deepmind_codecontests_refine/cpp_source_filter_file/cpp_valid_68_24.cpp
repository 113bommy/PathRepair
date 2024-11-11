#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i = 1;
    while (i * i < n) {
      i++;
    }
    int one = (i - 1) * (i - 10);
    if (one + i >= n) {
      cout << n - one << " " << i << endl;
    } else {
      cout << i << " " << (i) * (i)-n + 1 << endl;
    }
  }
  return 0;
}
