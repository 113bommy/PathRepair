#include <bits/stdc++.h>
using namespace std;
const int maxn = 200500;
const double esp = 1e-8;
long long A, B, n, l, t, m;
int main() {
  while (cin >> A >> B >> n) {
    while (n--) {
      cin >> l >> t >> m;
      if (A + (l - 1) * B > t) {
        printf("-1\n");
        continue;
      }
      long long ll = l, rr = 100000;
      long long sum = 0;
      while (ll <= rr) {
        long long mid = (ll + rr) >> 1;
        long long qian = A + (l - 1) * B;
        long long hou = A + (mid - 1) * B;
        if ((qian + hou) % 2 == 0) {
          sum = (qian + hou) / 2 * (mid - l + 1);
        } else {
          sum = (mid - l + 1) / 2 * (qian + hou);
        }
        long long temp = sum / m;
        if (sum % m != 0) temp++;
        long long ans = max(hou, temp);
        if (ans > t)
          rr = mid - 1;
        else
          ll = mid + 1;
      }
      printf("%d\n", rr);
    }
  }
}
