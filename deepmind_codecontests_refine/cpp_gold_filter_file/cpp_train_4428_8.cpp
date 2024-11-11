#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  if (n == 0) {
    cout << 1;
  } else {
    cout << 1 + (((6 + n * 6) * n) / 2);
  }
  return 0;
}
