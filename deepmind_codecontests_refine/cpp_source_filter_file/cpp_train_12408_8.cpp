#include <bits/stdc++.h>
using namespace std;
const int MAX = 0;
bool tab[11];
bool ans = 1;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int l, r;
  cin >> l >> r;
  int ans;
  for (int i = l + 1; i < r; i++) {
    ans = 0;
    for (int i = 0; i <= 10; i++) tab[i] = 0;
    int x = i;
    while (x > 0) {
      if (tab[x % 10]) {
        ans = true;
        break;
      } else {
        tab[x % 10] = true;
      }
      x /= 10;
    }
    if (!ans) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
