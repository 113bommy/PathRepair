#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n < 3)
    cout << -1;
  else {
    while (n) {
      cout << n;
      n--;
    }
  }
  return 0;
}
