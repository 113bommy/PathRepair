#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, l, r, count = 0, cursor = 1, i;
  cin >> n >> x;
  for (i = 0; i < n; i++) {
    cin >> l >> r;
    count = count + ((l - cursor) % 3) + (r - l + 1);
    cursor = r + 1;
  }
  cout << count;
  return 0;
}
