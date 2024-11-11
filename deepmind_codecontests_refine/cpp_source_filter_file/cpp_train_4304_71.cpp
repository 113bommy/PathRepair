#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long m = n * (n - 1) * 6;
  if (n > 1) {
    if (n == 1)
      cout << 1;
    else
      cout << m + 1;
  }
  return 0;
}
