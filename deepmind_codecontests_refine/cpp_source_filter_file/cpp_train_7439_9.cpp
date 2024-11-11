#include <bits/stdc++.h>
using namespace std;
const long double pi = 3.14159265359;
template <typename T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T sqr(T x) {
  return x * x;
}
int main() {
  int n;
  scanf("%d", &n);
  long long m = -1e18, p = -1e18, ans = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    m = max(m, ans - x);
    p = max(m, ans + x);
    ans = max(ans, m + x);
    ans = max(ans, p - x);
  }
  cout << ans << endl;
  return 0;
}
