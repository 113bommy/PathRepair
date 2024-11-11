#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n >> k;
    long long count = 0;
    while (n != 0) {
      if (n % k == 0) {
        n = n / k;
        count++;
      } else {
        long long rem = n % k;
        count += rem;
        n -= rem;
      }
    }
    cout << count << endl;
  }
  return 0;
}
