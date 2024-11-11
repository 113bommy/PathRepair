#include <bits/stdc++.h>
using namespace std;
const int ppr = 257;
const long long INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 9;
const int N = 1e6 + 123;
const long double pi = 3.141592653589793238462643;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, k, a[N], d[N], l, r, ans;
vector<int> v;
bool ch(int l) {
  if (l > n) return false;
  vector<int> q;
  for (int i = 1; i <= n; i++) {
    if (a[i] == a[i - 1]) continue;
    for (int j = 1; j <= d[a[i]] / l; j++) {
      q.push_back(a[i]);
      if (q.size() == k) break;
    }
  }
  if (q.size() >= k) {
    v = q;
    return 1;
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    d[a[i]]++;
  }
  sort(a + 1, a + n + 1);
  l = 1, r = inf;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (ch(mid)) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
  }
  for (int i = 0; i < v.size(); i++) cout << v[i] << ' ';
  return 0;
}
