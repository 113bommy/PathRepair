#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, i, x, c = 0;
  cin >> n >> x;
  for (i = 1; i <= n; i++) {
    if (x % i == 0 && (x / i) <= n) c++;
  }
  cout << c;
  return 0;
}
