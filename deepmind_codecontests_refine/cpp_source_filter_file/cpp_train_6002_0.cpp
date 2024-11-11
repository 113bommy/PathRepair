#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const char nl = '\n';
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, chip;
  cin >> n >> chip;
  int k = n * (n + 1) / 2;
  while (chip > k) {
    chip -= k;
  }
  if (chip < k) {
    int i = 1;
    while (i <= n) {
      if (chip < i) break;
      chip -= i;
      i++;
    }
    cout << chip;
  }
  return 0;
}
