#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  int cnt = n * (n - 1) / 2;
  if (cnt < k)
    cout << "no solution";
  else {
    for (int i = 1; i <= n; i++) {
      cout << 0 << ' ' << i << '\n';
    }
  }
}
