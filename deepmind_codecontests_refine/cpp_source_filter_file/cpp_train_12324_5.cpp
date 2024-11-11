#include <bits/stdc++.h>
using namespace std;
int main() {
  string bit;
  int num, sum = 0;
  cin >> num;
  for (int i = 0; i < num; i++) {
    cin >> bit;
    if (bit == "++x" || bit == "x++") {
      sum = sum + 1;
    } else if (bit == "x--" || bit == "--x") {
      sum = sum - 1;
    }
  }
  cout << sum;
  return 0;
}
