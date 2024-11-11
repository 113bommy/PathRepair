#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
pair<int, int> a[200002];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first;
  for (int i = 1; i <= n; i++) cin >> a[i].second;
  sort(a + 1, a + n + 1);
  int val = a[1].first;
  int poz = 1;
  long long ans = 0;
  long long sum = 0;
  set<pair<int, int> > second;
  while (poz <= n || !second.empty()) {
    while (poz <= n && a[poz].first == val) {
      second.insert({a[poz].second, poz});
      sum += a[poz].second;
      poz++;
    }
    if (second.empty()) {
      if (poz <= n) val = a[poz].first;
    } else {
      pair<int, int> p = *second.rbegin();
      second.erase(p);
      sum -= p.first;
      ans += sum;
      val++;
    }
  }
  cout << ans;
  return 0;
}
