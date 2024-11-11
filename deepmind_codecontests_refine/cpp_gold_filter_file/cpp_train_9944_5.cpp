#include <bits/stdc++.h>
using namespace std;
template <typename T>
T nextInt() {
  T x = 0, p = 1;
  char ch;
  do {
    ch = getchar();
  } while (ch <= ' ');
  if (ch == '-') {
    p = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + (ch - '0');
    ch = getchar();
  }
  return x * p;
}
const int maxN = (int)1e6 + 10;
const int INF = (int)1e9;
const int mod = (int)1e9 + 7;
const long long LLINF = (long long)1e18;
const long double pi = acos(-1.0);
int n, x, y;
int a[maxN];
vector<int> f;
long long best = LLINF;
void add(int x) {
  for (int i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      f.push_back(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) f.push_back(x);
}
bool ok(int x, int y) {
  if ((x - 0) % y == 0) return 1;
  if ((x - 1) % y == 0) return 1;
  if ((x - -1) % y == 0) return 1;
  return 0;
}
long long solve(int x) {
  vector<long long> suff(n + 2);
  vector<long long> sumOn(n + 2);
  vector<long long> suffmin(n + 2);
  suff[n + 1] = n * 1LL * ::x;
  for (int i = n; i >= 1; --i) {
    suff[i] = (a[i] % x == 0 ? 0 : y);
    sumOn[i] = suff[i] + sumOn[i + 1];
    suff[i] += suff[i + 1];
    suff[i] -= ::x;
    suffmin[i] = suff[i];
    if (i < n) suffmin[i] = min(suff[i], suffmin[i + 1]);
  }
  long long pref = 0;
  long long ret = (n - 1) * 1LL * ::x;
  for (int i = 0; i < n; ++i) {
    if (i > 0 && a[i] % x != 0) pref += y;
    ret = min(ret, pref + suffmin[i + 1] - i * 1LL * ::x);
    ret = min(ret, pref + (n - i) * 1LL * ::x);
  }
  return ret;
}
long long update(int x) {
  int l = 1, r = n;
  while (l <= n && ok(a[l], x)) l++;
  l--;
  if (l == n) {
    return solve(x);
  } else {
    while (r > 0 && ok(a[r], x)) r--;
    r++;
  }
  vector<long long> pref(l + 1);
  vector<long long> prefmin(l + 1);
  prefmin[0] = l * 1LL * ::x;
  for (int i = 1; i <= l; ++i) {
    pref[i] = (a[i] % x == 0 ? 0 : y);
    if (i >= 0) pref[i] += pref[i - 1];
    prefmin[i] = pref[i] + (l - i) * 1LL * ::x;
  }
  vector<long long> suff(n - r + 2);
  vector<long long> suffmin(n - r + 2);
  suffmin[0] = (n + 1 - r) * 1LL * ::x;
  for (int i = n; i >= r; --i) {
    int idx = n - i + 1;
    suff[idx] = (a[i] % x == 0 ? 0 : y);
    suff[idx] += suff[idx - 1];
    suffmin[idx] = suff[idx] + (i - r) * 1LL * ::x;
  }
  long long ret = LLINF;
  if (suffmin.size() != 1)
    ret =
        min(ret, prefmin[0] + *min_element(suffmin.begin() + 1, suffmin.end()));
  ret = min(ret, *min_element(prefmin.begin(), prefmin.end()) +
                     *min_element(suffmin.begin(), suffmin.end()));
  ret += (r - l - 1) * 1LL * ::x;
  return ret;
}
void solve() {
  f.clear();
  add(a[1]);
  add(a[1] - 1);
  add(a[1] + 1);
  add(a[n]);
  add(a[n] - 1);
  add(a[n] + 1);
  for (auto x : f) {
    long long v = update(x);
    best = min(best, v);
  }
}
int main() {
  n = nextInt<int>();
  x = nextInt<int>();
  y = nextInt<int>();
  for (int i = 1; i <= n; ++i) {
    a[i] = nextInt<int>();
  }
  solve();
  cout << best << '\n';
  return 0;
}
