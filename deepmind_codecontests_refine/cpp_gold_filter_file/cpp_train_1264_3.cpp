#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e8;
int l, r, cnt, ans1, pre1[20000005];
bitset<maxn> pre;
int max1, max2;
int main() {
  cin >> l >> r;
  pre[1] = pre[0] = 1;
  ans1 = 1;
  for (int yui = 2; yui <= r; yui++) {
    if (pre[yui] == 0) {
      cnt++;
      pre1[cnt] = yui;
      if (yui % 4 == 1) ans1++;
    }
    if (yui == l - 1) max1 = ans1;
    if (yui == r) max2 = ans1;
    for (int j = 1; j <= cnt && pre1[j] * yui <= r; j++) {
      pre[yui * pre1[j]] = 1;
      if (yui % pre1[j] == 0) break;
    }
  }
  cout << max2 - max1;
}
