#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n < 3) {
    cout << "-1";
  }
  if (n % 2 != 0) {
    cout << (n * n - 1) / 2 << " " << (n * n + 1) / 2;
  } else {
    cout << (n / 2) * (n / 2) - 1 << " " << (n / 2) * (n / 2) + 1;
  }
  return 0;
}
