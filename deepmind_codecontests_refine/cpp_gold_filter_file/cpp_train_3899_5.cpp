#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:300000000")
#pragma warning(disable : 4996)
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  int n, v;
  cin >> n >> v;
  vector<pair<int, int> > a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  sort(a.begin(), a.end());
  int c[3002];
  int cur = v;
  for (int i = 0; i <= 3001; i++) {
    c[i] = v;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int count = min(c[a[i].first], a[i].second);
    ans += count;
    c[a[i].first] -= count;
    a[i].second -= count;
    count = min(c[a[i].first + 1], a[i].second);
    ans += count;
    c[a[i].first + 1] -= count;
    a[i].second -= count;
  }
  cout << ans << endl;
  return 0;
}
