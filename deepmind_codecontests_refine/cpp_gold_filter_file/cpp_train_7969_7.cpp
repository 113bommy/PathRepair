#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
  cin >> n;
  if (n < 3) {
    cout << -1;
  } else if (n % 2) {
    cout << n * n / 2 << " " << n * n / 2 + 1;
  } else {
    cout << n * n / 4 - 1 << " " << n * n / 4 + 1;
  }
}
