#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1000000000")
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (n * (n - 1) / 2 > k) {
    int x = -1000;
    for (int(i) = (0); (i) < int(n); ++(i)) {
      cout << 0 << " " << x << endl;
      x++;
    }
  } else
    cout << "no solution";
  cin.sync();
  cin.get();
  return 0;
}
