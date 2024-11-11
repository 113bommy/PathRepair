#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  cin >> n >> k;
  if (k == 0 || k >= n) {
    cout << "0 0\n";
  } else {
    cout << 1 << " ";
    if (n >= k * 3) {
      cout << k * 2 << endl;
    } else
      cout << n - k << endl;
  }
}
