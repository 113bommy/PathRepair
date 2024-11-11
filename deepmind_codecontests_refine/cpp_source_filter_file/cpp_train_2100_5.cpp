#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
int n;
int k;
int m;
int i;
int a[N];
int d[N];
vector<pair<int, pair<int, int> > > b;
int can(int x) { return b[x - 1].first <= a[i]; }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    b.push_back({x, {y, i}});
  }
  sort(b.begin(), b.end());
  for (int i = 0; i < b.size(); i++) {
    d[i + 1] = d[i] + b[i].second.first;
  }
  for (i = 1; i <= n; i++) {
    int l = 0, r = n + 1;
    while (l < r) {
      m = (l + r) / 2;
      if (can(m + 1)) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    cout << d[l] << " ";
  }
}
