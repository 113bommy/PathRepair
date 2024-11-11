#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
long long n, m, k, a[10004];
int main() {
  scanf("%lld%lld%lld", &n, &m, &k);
  for (int(i) = (0); (i) < (n); (i)++) scanf("%lld", &a[i]);
  if (n % 2 == 0) {
    puts("0");
    return 0;
  }
  if (m < (n + 1) / 2) {
    puts("0");
    return 0;
  }
  long long ans = k * (m / ((n + 1) / 2));
  for (int i = 0; i < n; i += 2) {
    ans = min(ans, a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
