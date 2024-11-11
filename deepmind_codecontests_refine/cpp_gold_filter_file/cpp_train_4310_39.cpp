#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  if (k >= (n * n - n) / 2)
    puts("no solution");
  else {
    for (int i = 0; i < n; i++) cout << 0 << " " << i << endl;
  }
  return 0;
}
