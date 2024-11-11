#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k = 0, ans = 0;
  cin >> n;
  while (n > 0) {
    k++;
    n -= k;
  }
  cout << n + k;
  return 0;
}
