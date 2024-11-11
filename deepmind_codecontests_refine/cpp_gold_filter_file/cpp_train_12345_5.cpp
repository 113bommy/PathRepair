#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2) {
    cout << 7;
    n -= 3;
  }
  for (int i = 0; i < n / 2; i++) cout << 1;
  return 0;
}
