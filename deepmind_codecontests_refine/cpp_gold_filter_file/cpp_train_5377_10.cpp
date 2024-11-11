#include <bits/stdc++.h>
using namespace std;
int main() {
  long n;
  cin >> n;
  long dem = 0;
  if (n == 2 || n == 3) {
    cout << 1;
    return 0;
  }
  for (long i = 1; i < n; i++) {
    if (n % i == 0) dem++;
  }
  cout << dem;
}
