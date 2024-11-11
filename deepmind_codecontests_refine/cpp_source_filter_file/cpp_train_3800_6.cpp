#include <bits/stdc++.h>
using namespace std;
int n, i, sum, x;
int main() {
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    if (n * i >= x && x % i == 0) sum++;
  }
  cout << sum;
  return 0;
}
