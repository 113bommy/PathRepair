#include <bits/stdc++.h>
using namespace std;
int calc(int m, int n) {
  int ans = (200 * m + n) / (2 * n);
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  int t = 0;
  int p;
  multiset<pair<int, int> > s;
  for (int i = 0; i < k; i++) s.insert(make_pair(t + a[i], i));
  int m = 0, ans = 0, l = k;
  set<int> P;
  while (!s.empty()) {
    multiset<pair<int, int> >::iterator it = s.begin();
    int cur = (*it).first;
    int o = 0;
    while ((*s.begin()).first == cur) {
      m++;
      o++;
      s.erase(s.begin());
    }
    p = calc(m, n);
    while (l < n && o--) {
      s.insert(make_pair(cur + a[l], l));
      l++;
    }
    for (auto j : s) {
      if (j.first - (a[j.second] - p) - 0.5 < (*s.begin()).first &&
          j.first - (a[j.second] - p) > cur) {
        P.insert(j.second);
      }
    }
  }
  cout << (int)P.size() << endl;
}
