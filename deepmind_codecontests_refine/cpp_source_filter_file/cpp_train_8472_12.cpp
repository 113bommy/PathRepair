#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k;
  long long poss;
  cin >> n >> k;
  if (n % 2 == 0) {
    poss = n / 2;
  } else {
    poss = (n + 1) / 2;
  }
  if (poss > k) {
    cout << k * 2 - 1;
  } else {
    cout << (k - poss) * 2;
  }
  return 0;
}
