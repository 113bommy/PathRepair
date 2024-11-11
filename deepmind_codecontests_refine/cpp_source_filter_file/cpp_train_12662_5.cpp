#include <bits/stdc++.h>
using namespace std;
struct base {
  bitset<1001> d[1001];
  int sz = 0;
  void insert(bitset<1001> x) {
    for (int i = 1001 - 1; ~i; i--)
      if (x[i]) {
        if (d[i].any()) {
          d[i] = x;
          sz++;
          return;
        }
        x ^= d[i];
      }
  }
};
const int mod = 1e9 + 7;
int main() {
  int mp[75] = {}, id = 0;
  for (int n = 2; n <= 70; n++) {
    bool pr = true;
    for (int i = 2; i * i <= n; i++)
      if (n % i == 0) pr = false;
    if (pr) mp[n] = id++;
  }
  int n;
  scanf("%d", &n);
  base b;
  for (int a, i = 0; i < n; i++) {
    scanf("%d", &a);
    bitset<1001> bs;
    for (int j = 2; j <= a; j++)
      while (a % j == 0) {
        bs[mp[j]].flip();
        a /= j;
      }
    b.insert(bs);
  }
  int pw = n - b.sz, ans = 1;
  while (pw--) ans = (ans + ans) % mod;
  printf("%d\n", ans ? ans - 1 : mod - 1);
}
