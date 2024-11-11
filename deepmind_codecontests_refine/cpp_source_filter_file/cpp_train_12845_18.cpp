#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int mx = (n * (n - 1)) / 2;
  if (mx < k)
    cout << "no solution";
  else {
    for (int i = 0; i < n; i++) cout << 0 << " " << i << "\n";
  }
  return 0;
}
