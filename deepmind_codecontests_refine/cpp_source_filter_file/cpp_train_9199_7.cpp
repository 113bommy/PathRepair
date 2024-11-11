#include <bits/stdc++.h>
using namespace std;
int in() {
  int a;
  scanf("%d", &a);
  return a;
}
vector<long long> ha, ha2, po, po2;
const int INF = ~(1 << 31);
int main() {
  string s;
  cin >> s;
  string p;
  cin >> p;
  int k = in();
  set<char> ap;
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == '0') ap.insert('a' + i);
  }
  vector<int> pr(s.size() + 1, 0);
  for (int i = 0; i < s.size(); ++i) {
    pr[i + 1] = pr[i];
    if (ap.count(s[i]) > 0) {
      pr[i + 1]++;
    }
  }
  int pp = 257;
  po.push_back(1);
  for (int i = 0; i < s.size() + 2; ++i) po.push_back(po.back() * pp);
  ha.push_back(0);
  for (int i = 0; i < s.size(); ++i) ha.push_back(ha.back() + s[i] * po[i]);
  int pp2 = 37;
  po2.push_back(1);
  for (int i = 0; i < s.size() + 2; ++i) po2.push_back(po.back() * pp2);
  ha2.push_back(0);
  for (int i = 0; i < s.size(); ++i) ha2.push_back(ha2.back() + s[i] * po2[i]);
  int ans = 0;
  for (int i = 1; i <= s.size(); ++i) {
    set<pair<long long, long long> > res;
    for (int j = 0; j + i <= s.size(); ++j) {
      long long h = (ha[j + i] - ha[j]) * po[s.size() - j + 2];
      long long h2 = (ha2[j + i] - ha2[j]) * po2[s.size() - j + 2];
      if (pr[j + i] - pr[j] <= k) res.insert(make_pair(h, h2));
    }
    ans += res.size();
  }
  cout << ans << endl;
  return 0;
}
