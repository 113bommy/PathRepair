#include <bits/stdc++.h>
const long long int M = 1000000000;
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k == 240)
    cout << "0";
  else {
    int re = 240 - k;
    int p, sum = 0;
    for (int i = 1; i <= n; i++) {
      if (sum + i * 5 <= re) {
        sum += i * 5;
        p = i;
      } else
        break;
    }
    cout << p;
  }
  return 0;
}
