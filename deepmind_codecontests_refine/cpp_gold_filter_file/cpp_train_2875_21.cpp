#include <bits/stdc++.h>
using namespace std;
inline long long in() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const long long maxn = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long inf = 1e9 + 10;
int32_t main() {
  long long n = in(), k = in();
  long long mini = bool(n - k) && k, maxi = min(n - k, 2 * k);
  cout << mini << " " << maxi << "\n";
}
