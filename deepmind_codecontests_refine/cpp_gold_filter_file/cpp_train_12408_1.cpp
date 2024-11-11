#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int l, r, i;
  cin >> l >> r;
  for (i = l; i <= r; i++) {
    int num = i, f = 0, rem;
    int fre[11] = {0};
    while (num > 0) {
      rem = num % 10;
      fre[rem]++;
      if (fre[rem] > 1) {
        f = 1;
        break;
      }
      num /= 10;
    }
    if (f == 0) {
      cout << i;
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
