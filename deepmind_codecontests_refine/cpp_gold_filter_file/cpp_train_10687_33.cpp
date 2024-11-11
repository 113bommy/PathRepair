#include <bits/stdc++.h>
using namespace std;
int main() {
  long long number;
  int k;
  cin >> number >> k;
  while (k--) {
    if (number % 10 == 0) {
      number /= 10;
    } else
      number--;
  }
  cout << number;
}
