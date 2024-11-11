#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, temp = 0;
  cin >> n >> k;
  if ((k > n / 2) && (n % 2 == 0)) {
    temp = (k - (n / 2)) * 2;
  } else if ((k - 1 > n / 2) && (n % 2 == 1)) {
    temp = (k - 1 - (n / 2)) * 2;
  } else if ((k <= n / 2) && (n % 2 == 0)) {
    temp = (k * 2) - 1;
  } else if ((k <= 1 + n / 2) && (n % 2 == 1)) {
    temp = (k * 2) - 1;
  }
  cout << temp;
  return 0;
}
