#include <bits/stdc++.h>
using namespace std;
inline int cal(int a, int b, int c, int l) {
  int x = min(l, a - b - c);
  if (x < 0) return 0;
  return (long long)(x + 2) * (x + 1) / 2;
}
int main() {
  int a, b, c, l;
  cin >> a >> b >> c >> l;
  long long ans = (long long)(l + 1) * (l + 2) * (l + 3) / 6;
  for (int i = 0; i <= l; ++i) {
    ans -= cal(a + i, b, c, l - i);
    ans -= cal(b + i, a, c, l - i);
    ans -= cal(c + i, a, b, l - i);
  }
  cout << ans << endl;
  return 0;
}
