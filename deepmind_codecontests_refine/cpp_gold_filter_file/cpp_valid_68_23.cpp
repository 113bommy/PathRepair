#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long k;
    cin >> k;
    long long i = 1;
    while (i * i < k) i++;
    if (i * i == k)
      cout << i << " "
           << "1\n";
    else {
      if (k >= i * i - i + 1) {
        cout << i << " " << i * i - k + 1 << "\n";
      } else {
        cout << i - (i * i - i + 1 - k) << " " << i << "\n";
      }
    }
  }
}
