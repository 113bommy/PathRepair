#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  t = 1;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    k = n / 2;
    while (k > 0) {
      sum += (n - 1 + n - 2);
      n -= 2;
      k--;
    }
    cout << sum;
  }
}
