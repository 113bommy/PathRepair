#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  int kind[20] = {2, 7, 2, 3, 3, 3, 2, 5, 1, 2};
  int sum = 0;
  sum = kind[n % 10] * kind[n / 10];
  cout << sum;
  return 0;
}
