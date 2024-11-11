#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const int N = 1e5 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;
long long n;
long long check(long long x) {
  if (x <= 2) return x + 1;
  return check(x / 2) + check(x - (x / 2));
}
int main() {
  ios_base::sync_with_stdio(0);
  vector<long long> f{0, 2, 3};
  for (int i = 3;; ++i) {
    f.push_back(f[i - 1] + f[i - 2]);
    if (f.back() > MOD) break;
  }
  while (cin >> n) {
    int ans = 0;
    for (int i = 1; i < f.size(); ++i)
      if (f[i] <= n) ans = i;
    cout << ans << endl;
  }
  return 0;
}
