#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n;
  while (n != 0) {
    if (n % 8 == 1) k++;
    n /= 8;
  }
  cout << k;
  return 0;
}
