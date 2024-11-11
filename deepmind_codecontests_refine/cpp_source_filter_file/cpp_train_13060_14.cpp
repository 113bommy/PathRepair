#include <bits/stdc++.h>
using namespace std;
bool snt(long a) {
  for (int i = 2; i <= a / 2; i++) {
    if (i % 2 == 0) return false;
  }
  return true;
}
int main() {
  long a;
  cin >> a;
  int n = 9;
  if (a % 2 == 0)
    if (!snt(a - 9))
      cout << n << " " << a - n;
    else
      cout << n - 1 << " " << a - n + 1;
  else {
    cout << n << " " << a - n;
  }
}
