#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, b, a;
  cin >> n >> b;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  if (b <= n / 2) {
    a = b + 1;
  } else {
    a = b - 1;
  }
  cout << a;
  return 0;
}
