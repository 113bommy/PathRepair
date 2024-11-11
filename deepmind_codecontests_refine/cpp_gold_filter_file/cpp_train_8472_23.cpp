#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, s;
  cin >> n >> k;
  if (k < n / 2 + n % 2 + 1) {
    cout << (k - 1) * 2 + 1;
  } else {
    k -= n / 2 + n % 2;
    cout << k * 2;
  }
}
