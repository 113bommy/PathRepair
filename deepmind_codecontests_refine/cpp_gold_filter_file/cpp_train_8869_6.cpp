#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
int n;
long long a[N];
multiset<long long> m;
vector<pair<int, long long>> v;
long long pref[N];
int f[N];
vector<int> ans[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    m.insert(a[i]);
  }
  while (m.size()) {
    long long x = *m.begin();
    v.emplace_back(m.count(x), x);
    m.erase(x);
  }
  sort(v.begin(), v.end());
  int k = v.size();
  pref[0] = 0;
  for (int i = 1; i <= k; i++) {
    pref[i] = pref[i - 1] + v[i - 1].first;
  }
  int i = 0;
  long long best = -1, bestr = 1;
  for (long long r = 1; r * r <= n; r++) {
    while (i < k && v[i].first < r) i++;
    long long amt = r * ((pref[i] + (k - i) * r) / r);
    if (amt >= r * r && amt > best) {
      best = amt;
      bestr = r;
    }
  }
  int cnt = 0;
  for (int i = k - 1; i >= 0; i--) {
    for (int j = 0; j < bestr && j < v[i].first; j++) {
      ans[cnt % bestr].push_back(v[i].second);
      cnt++;
    }
  }
  for (int i = 0; i < cnt % bestr; i++) {
    ans[i].pop_back();
  }
  long long c = cnt / bestr;
  cout << (bestr * c) << endl << bestr << " " << c << endl;
  for (int i = 0; i < bestr; i++) {
    for (int j = 0; j < c; j++) {
      cout << ans[i][(j + c - i) % c] << " ";
    }
    cout << endl;
  }
}
