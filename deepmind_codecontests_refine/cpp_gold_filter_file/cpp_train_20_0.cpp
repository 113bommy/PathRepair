#include <bits/stdc++.h>
using namespace std;
const long long mxn = 1e6 + 7;
const long long mod = 1e9 + 7;
const long long inf = 1e18 + 7;
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};
pair<int, int> p[mxn];
map<long long, long long> f, s;
int n;
int a[mxn], ls[mxn];
long long ans;
void upd1(int x, int val) {
  while (x <= (int)1e8) {
    f[x] += val;
    x = (x | (x + 1));
  }
}
void upd2(int x) {
  while (x <= (int)1e8) {
    s[x]++;
    x = (x | (x + 1));
  }
}
long long sum1(int x) {
  long long res = 0;
  while (x > 0) {
    res += f[x];
    x = (x & (x + 1)) - 1;
  }
  return res;
}
int sum2(int x) {
  int res = 0;
  while (x > 0) {
    res += s[x];
    x = (x & (x + 1)) - 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].first;
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i].second;
    ls[i] = p[i].second;
  }
  sort(p + 1, p + n + 1);
  sort(ls + 1, ls + n + 1);
  for (int i = 1; i <= n; i++) {
    p[i].second = lower_bound(ls + 1, ls + n + 1, p[i].second) - ls;
  }
  for (int i = 1; i <= n; i++) {
    ans += (1LL * p[i].first * sum2(p[i].second)) - sum1(p[i].second);
    upd1(p[i].second, p[i].first);
    upd2(p[i].second);
  }
  cout << ans;
  return 0;
}
