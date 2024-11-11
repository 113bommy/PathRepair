#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, d = 0, m = 0, x = 0, k = 0, mn = 1e9 + 7, v = 0, w = 0, h = 0,
               i = 0, j = 0, l = 0, r = 0, c = 0, ans = 0;
  cin >> n >> k;
  vector<pair<int, pair<int, int>>> a(n);
  vector<pair<long long, long long>> z(n);
  set<int, greater<int>> b;
  for (int i = 0; i < n; i++) cin >> a[i].first;
  for (int i = 0; i < n; i++) {
    cin >> a[i].second.first;
    a[i].second.second = i;
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    v = k;
    h = 0;
    for (auto x : b) {
      if (v)
        h += x, v--;
      else {
        break;
      }
    }
    z[i].first = a[i].second.second;
    z[i].second = a[i].second.first + h;
    b.insert(a[i].second.first);
  }
  sort(z.begin(), z.end());
  for (int i = 0; i < n; i++) {
    cout << z[i].second << " ";
  }
  cout << endl;
}
