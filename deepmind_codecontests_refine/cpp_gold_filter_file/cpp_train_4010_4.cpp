#include <bits/stdc++.h>
using namespace std;
int k, n, i, ans, a[100005];
int sg0(int x) {
  if (x == 1 || x == 2) return x;
  return (x + 1) & 1;
}
int sg1(int x) {
  int tmp, tmp1, i;
  if (x == 1 || x == 3) return 1;
  if (x == 2) return 0;
  if (x & 1)
    return 0;
  else {
    tmp = sg1(x - 1);
    tmp1 = sg1(x >> 1);
    for (i = 0;; i++)
      if (i != tmp && i != tmp1) return i;
  }
}
int main() {
  while (cin >> n >> k) {
    k &= 1;
    ans = 0;
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n; i++) {
      if (!k)
        ans ^= sg0(a[i]);
      else
        ans ^= sg1(a[i]);
    }
    if (ans)
      cout << "Kevin" << endl;
    else
      cout << "Nicky" << endl;
  }
  return 0;
}
