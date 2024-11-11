#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int f[maxn], n;
string s;
inline long long get(int u, int v, int t) {
  if (u > v) return 0;
  if (t >= v) return 1ll * (v - u + 1) * t;
  if (t <= u) return 1ll * v * (v + 1) / 2 - 1ll * (u - 1) * u / 2;
  return 1ll * (t - u + 1) * t + 1ll * v * (v + 1) / 2 - 1ll * t * (t + 1) / 2;
}
long long cal(int l, int r) {
  if (l == r) return (s[l] == '1');
  int mid = l + r >> 1;
  long long ans = cal(l, mid) + cal(mid + 1, r);
  f[mid] = (s[mid] == '1');
  for (int i = mid - 1; i >= l; --i) f[i] = (s[i] == '1' ? f[i + 1] + 1 : 0);
  for (int i = mid - 1; i >= l; --i) f[i] = max(f[i], f[i + 1]);
  f[mid + 1] = (s[mid + 1] == '1');
  for (int i = mid + 2; i <= r; ++i) f[i] = (s[i] == '1' ? f[i - 1] + 1 : 0);
  for (int i = mid + 2; i <= r; ++i) f[i] = max(f[i], f[i - 1]);
  int x = 0, y = 0;
  for (int i = mid; i >= l; --i)
    if (f[i] == mid - i + 1) x = f[i];
  for (int i = mid + 1; i <= r; ++i)
    if (f[i] == i - mid) y = f[i];
  ans += 1ll * x * y * (y + 1) / 2;
  ans += 1ll * y * x * (x + 1) / 2;
  for (int i = mid - x; i >= l; --i) ans += get(x + 1, x + y, f[i]);
  vector<int> val;
  vector<long long> sum;
  for (int i = mid + 1 + y; i <= r; ++i) {
    ans += get(y + 1, y + x, f[i]);
    val.emplace_back(max(x + y, f[i]));
  }
  for (int i = 0; i < val.size(); ++i)
    if (i == 0)
      sum.emplace_back(val[0]);
    else
      sum.emplace_back(sum.back() + val[i]);
  if (val.size())
    for (int i = mid - x; i >= l; --i) {
      int pos = upper_bound(val.begin(), val.end(), f[i]) - val.begin() - 1;
      ans += sum.back();
      if (pos >= 0) ans -= sum[pos];
      ans += 1ll * f[i] * (pos + 1);
    }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> s;
  s = " " + s;
  cout << cal(1, n) << '\n';
}
