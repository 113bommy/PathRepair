#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a = 0, b;
  cin >> n;
  b = n;
  bool result = false;
  for (int i = 1; i <= n + 1 / 2; i++) {
    a += i;
    if (a == b) {
      result = true;
      break;
    }
  }
  if (result)
    cout << "YES";
  else
    cout << "NO";
}
