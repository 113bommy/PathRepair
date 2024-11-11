#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    long long k, x;
    cin >> k >> x;
    cout << 9 * (k - 1) + x << "\n";
  }
}
