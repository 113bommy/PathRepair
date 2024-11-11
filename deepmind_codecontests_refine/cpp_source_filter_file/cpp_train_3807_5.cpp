#include <bits/stdc++.h>
using namespace std;
int prime(int n) {
  int i, test = 0;
  for (i = 3; i < sqrt(n); i = i + 2)
    if (n % i == 0) {
      test = 1;
      break;
    }
  return test;
}
int main() {
  int n;
  cin >> n;
  if (n % 2 == 0) {
    if (n == 2)
      cout << 1;
    else
      cout << 2;
  } else {
    if (prime(n) == 0)
      cout << 1;
    else {
      if (prime(n - 2) == 0)
        cout << 2;
      else
        cout << 3;
    }
  }
}
