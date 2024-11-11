#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  int count = 0;
  cin >> n >> x;
  if (n >= x) count++;
  for (int i = 2; i <= n; i++) {
    if (x % i == 0 && x / i <= n) {
      count++;
    }
  }
  cout << count;
  return 0;
}
