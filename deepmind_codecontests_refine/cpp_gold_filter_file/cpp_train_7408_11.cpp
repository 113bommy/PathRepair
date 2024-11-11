#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n % 2 != 0)
    cout << 0;
  else {
    int val = n / 2;
    cout << (1 << val);
  }
  return 0;
}
