#include <bits/stdc++.h>
using namespace std;
int main(void) {
  long long int r, l, i, j;
  int cnt = 0;
  cin >> l >> r;
  for (i = 1; i <= 2000000000; i *= 2) {
    for (j = 1; j <= 2000000000; j *= 2) {
      if ((i * j) >= l && (i * j) <= r) cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}
