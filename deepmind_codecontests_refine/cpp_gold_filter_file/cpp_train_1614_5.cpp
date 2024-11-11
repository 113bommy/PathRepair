#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1100, INF = 1000000007;
int a, b, c, l;
long long ans, temp;
long long C(long long x) {
  if (x < 2) return 0;
  return x * (x - 1) / 2;
}
int main() {
  cin >> a >> b >> c >> l;
  ans = 0;
  for (int i = 0; i <= l; i++) {
    int s = a + b + c + i, limit = (a + b + c + i - 1) / 2;
    if (a > limit || b > limit || c > limit) continue;
    temp = C(i + 2);
    temp -= C(i - (limit - a) + 1) + C(i - (limit - b) + 1) +
            C(i - (limit - c) + 1);
    ans += temp;
  }
  cout << ans << endl;
  return 0;
}
