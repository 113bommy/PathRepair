#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, n;
  cin >> n >> a >> b;
  a--;
  int res = 0;
  if (b >= 0) {
    res = (a + b % n) % n;
  } else {
    res = (a + (n + b % n)) % n;
  }
  cout << res + 1 << endl;
  return 0;
}
