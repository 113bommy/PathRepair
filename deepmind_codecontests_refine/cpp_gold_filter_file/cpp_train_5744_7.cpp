#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 5;
const long long mod = 1e9 + 7;
int main() {
  int t = 1;
  while (t--) {
    long long n, temp, sum;
    cin >> n;
    for (int i = n; i <= 1003; i++) {
      sum = 0;
      temp = i;
      while (temp) {
        sum += temp % 10;
        temp = temp / 10;
      }
      if (sum % 4 == 0) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
