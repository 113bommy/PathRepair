#include <bits/stdc++.h>
using namespace std;
bool checkluck(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  if (sum % 4 == 0)
    return true;
  else
    return false;
}
int getrem(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum % 4;
}
int main() {
  int n;
  cin >> n;
  while (1) {
    if (checkluck(n)) {
      cout << n;
      return 0;
    } else {
      n += getrem(n);
    }
  }
}
