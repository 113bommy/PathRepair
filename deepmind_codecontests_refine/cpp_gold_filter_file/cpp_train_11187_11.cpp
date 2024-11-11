#include <bits/stdc++.h>
template <class T>
T gcd(T a, T b) {
  while (a && b)
    if (a > b)
      a %= b;
    else
      b %= a;
  return a + b;
}
using namespace std;
const int inf = 1e9 + 7;
pair<int, int> ans[1111], a[1111];
int sum, mx;
int main() {
  ios_base::sync_with_stdio(false);
  int n, k, i, j;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].second = i + 1;
    sum += a[i].first;
  }
  mx = (bool)(!sum % 3);
  for (i = 0; i < k; i++) {
    sort(a, a + n);
    int p = a[n - 1].first - a[0].first;
    if (p == mx) {
      cout << mx << " " << i << endl;
      for (j = 0; j < i; j++)
        cout << ans[j].first << " " << ans[j].second << endl;
      return 0;
    }
    a[0].first++;
    a[n - 1].first--;
    ans[i] = make_pair(a[n - 1].second, a[0].second);
  }
  sort(a, a + n);
  cout << a[n - 1].first - a[0].first << " " << k << endl;
  for (i = 0; i < k; i++) cout << ans[i].first << " " << ans[i].second << endl;
  return 0;
}
