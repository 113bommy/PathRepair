#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    unsigned long long n;
    cin >> n;
    unsigned long long currMin = n, i = 1;
    while (i < currMin) {
      unsigned long long curr = ((n - 1) / i) + (i - 1);
      currMin = min(currMin, curr);
      i++;
    }
    if (n == 1) currMin = 1;
    cout << currMin << endl;
  }
}
