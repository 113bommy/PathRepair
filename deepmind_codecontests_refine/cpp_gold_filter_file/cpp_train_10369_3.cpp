#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INFLL = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const int big = 1e18;
long long x, y, l, r;
long long a[105], b[105];
vector<long long> c;
int main() {
  cin >> x >> y >> l >> r;
  c.clear();
  long long tmp = 1;
  int cnt1 = 0;
  while (1) {
    if (x > (r / tmp)) break;
    tmp *= x;
    a[cnt1++] = tmp;
  }
  a[cnt1++] = 1;
  tmp = 1;
  int cnt2 = 0;
  while (1) {
    if (y > (r / tmp)) break;
    tmp *= y;
    b[cnt2++] = tmp;
  }
  b[cnt2++] = 1;
  for (int i = 0; i < cnt1; i++) {
    for (int j = 0; j < cnt2; j++) {
      if (a[i] + b[j] > r) continue;
      c.push_back(a[i] + b[j]);
    }
  }
  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());
  long long lb = -1, rb = -1;
  for (int i = 0; i < c.size(); i++) {
    if (c[i] >= l) {
      lb = i;
      break;
    }
  }
  for (int i = 0; i < c.size(); i++) {
    if (c[i + 1] > r) {
      rb = i;
      break;
    }
  }
  long long ans = 0;
  if (lb == -1)
    ans = r - l + 1;
  else {
    if (rb == -1) rb = c.size() - 1;
    for (int i = lb; i < rb; i++) {
      ans = max(ans, c[i + 1] - c[i] - 1);
    }
    ans = max(ans, max(c[lb] - l, r - c[rb]));
  }
  cout << ans << endl;
  return 0;
}
