#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n;
    cin >> k;
    long long count = 0;
    while (n != 0) {
      count += (1 + n % k);
      n = (n - n % k) / k;
    }
    count -= 1;
    cout << count << endl;
  }
}
