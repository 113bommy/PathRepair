#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 1)
    cout << 1;
  else {
    cout << n << " ";
    cout << 1 << " ";
    for (int i = 2; i < n; i++) cout << i << " ";
  }
  return 0;
}
