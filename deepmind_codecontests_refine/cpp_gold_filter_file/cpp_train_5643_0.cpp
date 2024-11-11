#include <bits/stdc++.h>
using namespace std;
void blowback() {
  long long i, j, l, k, n, x, y, m, ans;
  string s;
  cin >> n >> m;
  pair<pair<long long, long long>, long long> a[n];
  for (i = 0; i < n; i++) {
    cin >> a[i].first.first >> a[i].first.second;
    a[i].second = i;
  }
  sort(a, a + n);
  multiset<pair<long long, long long> > ms;
  vector<long long> v;
  for (i = 1, j = 0; i <= 200000; i++) {
    while (a[j].first.first <= i) {
      ms.insert({a[j].first.second, a[j].second});
      j++;
    }
    while ((*ms.begin()).first < i) {
      ms.erase(ms.begin());
    }
    while (ms.size() > m) {
      auto it = ms.end();
      it--;
      v.push_back((*it).second);
      ms.erase(it);
    }
  }
  sort((v).begin(), (v).end());
  cout << v.size() << "\n";
  for (i = 0; i < v.size(); i++) cout << v[i] + 1 << " ";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int t = 1;
  while (t--) {
    blowback();
  }
  return 0;
}
