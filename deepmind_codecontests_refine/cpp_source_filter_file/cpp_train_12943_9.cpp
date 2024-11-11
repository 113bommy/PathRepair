#include <bits/stdc++.h>
using namespace std;
long long f(long long x) {
  long long p, ans, cnt;
  p = 1;
  ans = 0;
  for (int i = 0; i < 60; i++) {
    cnt = ((x + 1) / (2 * p)) * p;
    if (((x + 1) % (2 * p)) > p) cnt += (((x + 1) % (2 * p)) - p);
    if (cnt & 1) ans += p;
    p *= 2;
  }
  return ans;
}
int main() {
  long long ans, x, m;
  int n, i;
  ans = 0;
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x >> m;
    ans ^= f(x + m - 1);
    ans ^= f(x + 1);
  }
  if (ans)
    cout << "tolik" << endl;
  else
    cout << "bolik" << endl;
  return 0;
}
