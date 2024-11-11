#include <bits/stdc++.h>
using namespace std;
int summ(int n) {
  int sum = 0;
  while (n != 0) {
    int a = n % 10;
    sum += a;
    n /= 10;
  }
  return sum;
}
int main() {
  int n;
  cin >> n;
  int p = n;
  int k = summ(n) % 4;
  while (k % 4 != 0) {
    if (k == 0)
      cout << p;
    else {
      p = p + 1;
      int sum1 = 0;
      sum1 = summ(p);
      k = sum1 % 4;
    }
  }
  cout << p;
  return 0;
}
