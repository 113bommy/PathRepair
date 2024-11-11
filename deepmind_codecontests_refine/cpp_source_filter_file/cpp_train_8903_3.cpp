#include <bits/stdc++.h>
using namespace std;
const int OO = (int)1e9 + 7;
const int MX = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const double EPS = 1e-6;
const double PI = 3.1415926;
int main(void) {
  int n, q;
  scanf("%d%d", &n, &q);
  int t[q], sh[q];
  for (int i = 0; i < q; i++) {
    scanf("%d", &t[i]);
    if (t[i] == 1) {
      scanf("%d", &sh[i]);
    }
  }
  int cur = 1;
  long long tot = 0, odd = 0, even = 0;
  for (int i = 0; i < q; i++) {
    if (t[i] == 1) {
      tot += sh[i];
      if (tot > n || tot < 0) {
        tot = (tot + n) % n;
      }
      if (abs(sh[i]) % 2) {
        cur = 1 - cur;
      }
    } else {
      if (cur == 1) {
        odd++;
        even--;
      } else {
        even++;
        odd--;
      }
      if (odd > n || odd < 0) {
        odd = (odd + n) % n;
      }
      if (even > n || even < 0) {
        even = (even + n) % n;
      }
      cur = 1 - cur;
    }
  }
  int res[n];
  for (int i = 1; i <= n; i++) {
    if (i & 1) {
      long long val = i - 1 + tot + odd + n;
      if (val > n || val < 0) {
        val %= n;
      }
      res[val] = i;
    } else {
      long long val = (i - 1 + tot + even + n);
      if (val > n || val < 0) {
        val %= n;
      }
      res[val] = i;
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d ", res[i]);
  }
  puts("\n");
  return 0;
}
