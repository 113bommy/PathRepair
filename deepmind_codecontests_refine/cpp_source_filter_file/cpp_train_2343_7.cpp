#include <bits/stdc++.h>
using namespace std;
inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int& n, int b) { n |= two(b); }
inline void unset_bit(int& n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) {
  int res = 0;
  while (n && ++res) n -= n & (-n);
  return res;
}
int a[2123456];
int main() {
  int n, w, ans = 0;
  scanf("%d", &n);
  memset(a, 0, sizeof a);
  for (int i = 0; i < n; i++) {
    scanf("%d", &w);
    a[w]++;
  }
  for (int i = 0; i <= 1000000; i++) {
    a[i + 1] += a[i] / 2;
    a[i] %= 2;
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
