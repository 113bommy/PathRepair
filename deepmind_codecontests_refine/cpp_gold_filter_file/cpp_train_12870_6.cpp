#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = 1e18 + 10;
const int MAX = 1e5 + 10;
int n, x, k;
int a[MAX];
int upperbs(int x) {
  int l = 1, r = n, i = (l + r) / 2;
  while (l != i && i != r) {
    if (a[i] <= x)
      l = i;
    else
      r = i;
    i = (l + r) / 2;
  }
  for (int i = r; i >= l; i--)
    if (a[i] <= x) return i;
  return 0;
}
int lowerbs(int x) {
  int l = 1, r = n, i = (l + r) / 2;
  while (l != i && i != r) {
    if (a[i] >= x)
      r = i;
    else
      l = i;
    i = (l + r) / 2;
  }
  for (int i = l; i <= r; i++)
    if (a[i] >= x) return i;
  return n + 1;
}
void process() {
  cin >> n >> x >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int q = a[i] / x;
    if (q < k) continue;
    int l = (q - k) * x + 1;
    int r = min(a[i], (q - k + 1) * x);
    res += max(0, upperbs(r) - lowerbs(l) + 1);
  }
  cout << res;
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
