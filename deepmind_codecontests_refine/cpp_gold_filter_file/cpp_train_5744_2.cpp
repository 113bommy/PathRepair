#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5, MOD = 1e9 + 7;
int n;
int ok(int x) {
  int s = 0;
  while (x > 0) {
    s += x % 10;
    x /= 10;
  }
  if (s % 4 == 0)
    return 1;
  else
    return 0;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = n; i <= 2000; i++) {
    if (ok(i)) {
      cout << i << endl;
      break;
    }
  }
  return 0;
}
