#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int k = 2, c = 2;
  for (int i = 1; i <= n - 1; i++) {
    cout << k;
    k = k + c;
    c++;
    if (k > n) k = k - n;
  }
  return 0;
}
