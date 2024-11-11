#include <bits/stdc++.h>
using namespace std;
int main() {
  long int a, sum, mod;
  long int n, b, d, count;
  while (cin >> n >> b >> d) {
    count = 0;
    sum = 0;
    for (int i = 1; i <= n; i++) {
      cin >> a;
      if (a < b) {
        sum = sum + a;
        if (sum > d) {
          count++;
          sum = 0;
        }
      }
    }
    cout << count << endl;
  }
  return 0;
}
