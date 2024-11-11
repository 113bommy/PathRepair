#include <bits/stdc++.h>
using namespace std;
int n;
pair<long long, int> a[200005];
bool dd[1000005];
bool cmp(const pair<long long, int> &a, const pair<long long, int> &b) {
  return a.first > b.first;
}
int main() {
  cout << setprecision(10) << fixed;
  ios::sync_with_stdio(false), cin.tie(0);
  cin >> n;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    sum += a[i].first;
    a[i].second = i + 1;
  }
  sort(a, a + n, cmp);
  int res = 0;
  if (a[1].first == sum - a[1].first - a[0].first)
    res++, dd[a[0].second] = true;
  for (int i = 1; i < n; i++)
    if (a[0].first == sum - a[i].first - a[0].first)
      res++, dd[a[i].second] = true;
  cout << res << endl;
  for (int i = 1; i <= n; i++)
    if (dd[i]) cout << i << ' ';
  return 0;
}
