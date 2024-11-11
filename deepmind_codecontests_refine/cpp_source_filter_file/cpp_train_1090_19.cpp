#include <bits/stdc++.h>
using namespace std;
int main() {
  long long h, n;
  cin >> h >> n;
  long long l, r, cnt = 0, node = 1L, mid;
  l = 1LL;
  r = ((1LL) << 40);
  while (l < r) {
    mid = (l + r) / 2;
    if (n <= mid) {
      if ((node % 2) == 1) {
        cnt++;
      } else {
        cnt += (r - l + 1);
      }
      r = mid;
      node = node * 2;
    } else {
      if ((node % 2) == 1) {
        cnt += (r - l + 1);
      } else {
        cnt++;
      }
      l = mid + 1;
      node = node * 2 + 1;
    }
  }
  cout << cnt;
}
