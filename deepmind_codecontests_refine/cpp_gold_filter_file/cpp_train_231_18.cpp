#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    int count = 0, sum = 0;
    while (n % 2 == 0) {
      count++;
      n = n / 2;
    }
    while (n % 3 == 0) {
      sum++;
      n = n / 3;
    }
    if (n == 1 && sum >= count) {
      cout << 2 * sum - count;
    } else {
      cout << -1;
    }
    cout << endl;
  }
}
