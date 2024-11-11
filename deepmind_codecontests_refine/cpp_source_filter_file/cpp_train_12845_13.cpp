#include <bits/stdc++.h>
using namespace std;
int n, k;
int main() {
  cin >> n >> k;
  if (k > n * (n - 1) / 2) return puts("no solution");
  for (int i = 0; i < n; ++i) cout << 0 << ' ' << i << endl;
}
