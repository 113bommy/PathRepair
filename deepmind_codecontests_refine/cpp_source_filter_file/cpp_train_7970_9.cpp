#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k, i;
  long long sum = 0;
  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    sum += i * 5;
    if ((k + sum) >= 240) {
      cout << i - 1 << endl;
      break;
    }
  }
  if (i - 1 == n) cout << n << endl;
}
