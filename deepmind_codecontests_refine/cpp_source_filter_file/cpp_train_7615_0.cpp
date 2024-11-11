#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    int count = 0;
    while (n) {
      if (n % k == 0) {
        n = n / k;
        count++;
      } else {
        count += n % k;
        n = n - n % k;
      }
    }
    cout << count << endl;
  }
}
