#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int r = 1;
  for (int i = 1; i <= n - 1; i++) {
    r = (r + i) % n;
    if (r == n) r = 0;
    cout << r << " ";
  }
  return 0;
}
