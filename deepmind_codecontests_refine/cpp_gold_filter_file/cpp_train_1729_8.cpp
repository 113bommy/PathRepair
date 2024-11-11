#include <bits/stdc++.h>
using namespace std;
inline int _ceil(int a, int b) { return (a + b - 1) / b; }
int main() {
  long long n, k;
  scanf("%lld", &n);
  ;
  scanf("%lld", &k);
  ;
  long long sm = k;
  long long a[n], x, y, ans = -1;
  set<long long> st;
  for (x = 0; x < n; x++) {
    scanf("%lld ", a + x);
    for (y = 1; y <= sqrt(a[x]); y++) {
      st.insert(_ceil(a[x], y));
      st.insert(y);
    }
    sm += a[x];
  }
  for (auto it : st) {
    long long add = 0;
    for (x = 0; x < n; x++) add += _ceil(a[x], it);
    long long d = sm / add;
    if (it <= d && ans < d) ans = d;
  }
  printf("%lld", ans);
}
