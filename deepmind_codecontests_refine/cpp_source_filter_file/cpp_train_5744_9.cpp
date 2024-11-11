#include <bits/stdc++.h>
using namespace std;
int fun(int a) {
  int sum = 0;
  for (int i = 1; i <= 3; i++) {
    sum = sum + (a % 10);
    a = a / 10;
  }
  return sum;
}
int main() {
  int n, m, p;
  cin >> n;
  m = n;
  for (int i = 1;; i++) {
    if (fun(m) % 4 == 0)
      break;
    else {
      m++;
      n = m;
    }
  }
  cout << n;
}
