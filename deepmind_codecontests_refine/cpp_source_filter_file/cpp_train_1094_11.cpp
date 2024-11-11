#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 50;
int a[N], par[N];
int n;
long double check(int k, int in) {
  if (k == 0 || n - k < in || in <= k) return 0;
  long double sum = par[in] - par[in - k - 1] + par[n] - par[n - k];
  long double ans = 1.0 * sum / (1.0 * 2 * k + 1);
  ans -= a[in];
  return ans;
}
void pnt(int k, int in) {
  cout << (2 * k + 1) << '\n';
  for (int i = in - k; i <= in; i++) cout << a[i] << " ";
  for (int i = n - k + 1; i <= n; i++) cout << a[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) par[i] = par[i - 1] + a[i];
  pair<int, int> ans = make_pair(0, 1);
  long double mx = 0;
  for (int i = 1; i <= n; i++) {
    int l = -1, r = i;
    for (int j = 0; j < 200; j++) {
      int mid = (l + r) / 2;
      if (l + 1 == r) break;
      if (check(mid, i) > check(mid - 1, i))
        l = mid;
      else
        r = mid;
    }
    if (check(l, i) > mx) {
      mx = check(l, i);
      ans.first = l;
      ans.second = i;
    }
  }
  pnt(ans.first, ans.second);
  return 0;
}
