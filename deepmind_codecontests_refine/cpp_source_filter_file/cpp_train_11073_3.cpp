#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  cin >> n;
  if (n == 1 || n == 2) {
    cout << -1;
    return 0;
  }
  for (i = 1; i <= n; i++) cout << n << " ";
}
