#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, num, numm, sum = 0;
  cin >> n >> num;
  numm = num;
  while (num != 0) {
    num = num / 10;
    sum++;
  }
  if (n == 1 && num == 10)
    cout << "-1";
  else if (n == sum)
    cout << num;
  else if (n < sum)
    cout << "-1";
  else {
    cout << numm;
    for (int i = 0; i < n - sum; i++) cout << "0";
  }
}
