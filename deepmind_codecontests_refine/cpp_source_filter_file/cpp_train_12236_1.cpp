#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int r;
  r = (a + b) % n;
  if (r == 0) r = n;
  if (r < 0) {
    r = r * -1;
  }
  cout << r << endl;
  return 0;
}
