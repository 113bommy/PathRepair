#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
const double PI = acos(-1.0);
const int N = 100000 + 10;
int a[N];
int main() {
  int k, b, n;
  scanf("%d", &(k)), scanf("%d", &(b)), scanf("%d", &(n));
  for (int i(1), _h(n); i <= _h; ++i) scanf("%d", &(a[i]));
  int m = k - 1;
  int s = 0;
  long long ans = 0;
  map<int, int> cnt;
  cnt[0] = 1;
  for (int i(1), _h(n); i <= _h; ++i) {
    s += a[i];
    s %= m;
    int pre = (s - b + m) % m;
    ans += cnt[pre];
    ++cnt[s];
  }
  long long ans0 = 0, tmp = 0;
  a[n + 1] = 1;
  for (int i(1), _h(n + 1); i <= _h; ++i) {
    if (a[i] == 0) {
      tmp++;
    } else {
      ans0 += (long long)tmp * (tmp + 1) / 2;
      tmp = 0;
    }
  }
  if (b == 0)
    cout << ans0;
  else if (b == m)
    cout << ans - ans0;
  else
    cout << ans;
  return 0;
}
