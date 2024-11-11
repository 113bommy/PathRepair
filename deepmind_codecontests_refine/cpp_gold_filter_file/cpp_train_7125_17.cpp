#include <bits/stdc++.h>
using namespace std;
int const lim = 1e5;
int inp[lim + 3], pre[lim + 3], suf[lim + 3], n;
bool check(int x) {
  for (int i = x; i <= n; i++) {
    int ind1 = pre[i];
    int ind = suf[i - x + 1];
    if (ind1 != ind + 1) continue;
    if (ind1 == i || (inp[ind + 2] - inp[ind] >= 2 && inp[ind + 2] > inp[ind]))
      return true;
    if (ind == i - x + 1 ||
        (inp[ind1] - inp[ind1 - 2] >= 2 && inp[ind1] > inp[ind1 - 2]))
      return true;
  }
  return false;
}
int main() {
  cin >> n;
  inp[n] = 1e9 + 4;
  inp[0] = -10;
  for (int i = 1; i <= n; i++) scanf("%d", &inp[i]);
  int last = 1, last_val = -10;
  ;
  for (int i = 1; i <= n; i++) {
    if (inp[i] > last_val)
      pre[i] = last, last_val = inp[i];
    else
      pre[last] = last = i, last_val = inp[i];
  }
  last = n;
  last_val = 1e9 + 3;
  for (int i = n; i >= 1; i--) {
    if (inp[i] < last_val)
      suf[i] = last, last_val = inp[i];
    else
      suf[i] = last = i, last_val = inp[i];
  }
  if (pre[n] == 1) {
    cout << n << endl;
    return 0;
  }
  int lo = 1, hi = n;
  while (lo < hi) {
    if (lo == hi - 1) {
      if (check(hi)) lo = hi;
      break;
    }
    int mid = (lo + hi) / 2;
    if (check(mid))
      lo = mid;
    else
      hi = mid - 1;
  }
  check(lo + 1);
  cout << lo << endl;
}
