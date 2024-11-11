#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a, long long int b) {
  return (b == 0LL ? a : gcd(b, a % b));
}
long double dist(long double x1, long double arayikhalatyan, long double x2,
                 long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) +
              (arayikhalatyan - y2) * (arayikhalatyan - y2));
}
long long int S(long long int a) { return (a * (a + 1LL)) / 2; }
char vow[] = {'a', 'e', 'i', 'o', 'u'};
int dx[] = {1, -1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int N = 3e6 + 30;
const long long int mod = 998244353;
const long double pi = acos(-1);
const int T = 238;
const long double e = 1e-6;
long long int bp(long long int a, long long int b = mod - 2LL) {
  long long int ret = 1;
  while (b) {
    if (b & 1) ret *= a, ret %= mod;
    a *= a;
    a %= mod;
    b >>= 1;
  }
  return ret;
}
ostream& operator<<(ostream& c, pair<int, int> a) {
  c << a.first << " " << a.second;
  return c;
}
int n, k;
int a[N], col[N];
bool stg(int x) {
  int sm = 0;
  for (int i = 0; i < x; i++) {
    col[a[i]]++;
    if (col[a[i]] > 1) continue;
    sm++;
  }
  if (sm <= k) return true;
  int l = 0, r = x - 1;
  while (r < n - 1) {
    col[a[l]]--;
    if (col[a[l]] == 0) sm--;
    l++;
    r++;
    col[a[r]]++;
    if (col[a[r]] == 1) sm++;
    if (sm <= k) return true;
  }
  return false;
}
void maq() {
  for (int i = 0; i < n; i++) col[a[i]] = 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int l = 1, r = n, ans = 1;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (stg(mid))
      l = mid + 1, ans = mid;
    else
      r = mid - 1;
    maq();
  }
  int x = ans;
  int sm = 0;
  for (int i = 0; i < x; i++) {
    col[a[i]]++;
    if (col[a[i]] > 1) continue;
    sm++;
  }
  l = 0, r = x - 1;
  if (sm <= k) return cout << l + 1 << " " << l + ans, 0;
  while (r < n - 1) {
    col[a[l]]--;
    if (col[a[l]] == 0) sm--;
    l++;
    r++;
    col[a[r]]++;
    if (col[a[r]] == 1) sm++;
    if (sm <= k) return cout << l + 1 << " " << l + ans, 0;
  }
  return 0;
}
