#include <bits/stdc++.h>
using namespace std;
const long long Maxn = 1e5 + 7;
const long long Inf = 1e9 + 7;
long long a, b, c, w, x, xp, st, en, ans;
bool check(long long m) {
  long long k = ((m * x) - b + w - 1) / w;
  return (a - k >= c - m);
}
void BYS() {
  if (st > en) return;
  long long mid = (st + en) / 2;
  bool t = check(mid);
  if (t) ans = min(ans, mid);
  if (t)
    en = mid - 1;
  else
    st = mid + 1;
  BYS();
}
int main() {
  cin >> a >> b >> w >> x >> c;
  xp = w - x;
  st = 0, en = Inf;
  BYS();
  cout << st << endl;
}
