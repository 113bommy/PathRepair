#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, i, sum = 0;
  cin >> a;
  for (i = 1; i <= a; i++) {
    if (i == 1)
      sum = sum + 1;
    else
      sum = sum + 6 * pow(2, i - 1);
  }
  cout << sum;
}
