#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
inline string get() {
  char ch[1000010];
  scanf("%s", ch);
  return ch;
}
const int MAX_LG = 22;
const long long maxn = 1e5 + 100;
const long long base = 29;
const long long mod = 1e9 + 7;
const long long INF = 1e9 + 100;
long long xo, n, k;
long long a[] = {0, 1, 0, 1, 2};
inline long long grundy(long long val) {
  if (k % 2 == 0) {
    if (val == 1) return 1;
    if (val == 2) return 2;
    return !(val % 2);
  } else {
    if (val < 5) return a[val];
    if (val % 2) return 0;
    long long v2 = grundy(val / 2);
    if (v2 == 0) return 1;
    return 2;
  }
}
int32_t main() {
  n = in(), k = in();
  for (long long i = 0; i < n; i++) xo ^= grundy(in());
  if (xo)
    cout << "Kevin\n";
  else
    cout << "Nicky\n";
}
