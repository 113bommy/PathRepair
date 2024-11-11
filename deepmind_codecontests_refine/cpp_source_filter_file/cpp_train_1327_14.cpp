#include <bits/stdc++.h>
using namespace std;
int main() {
  int num1, num2;
  cin >> num1 >> num2;
  string Die_Roll[6] = {"1/6", "1/3", "1/2", "2/3", "5/6", "1"};
  int x = 0;
  x = max(num1, num2);
  cout << Die_Roll[6 - x] << endl;
  return 0;
}
