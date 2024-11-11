#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> prefix_function(vector<long long> s) {
  int n = (int)s.size();
  vector<int> pi(n);
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) j = pi[j - 1];
    if (s[i] == s[j]) j++;
    pi[i] = j;
  }
  return pi;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<long long, char> > a, b;
  for (int i = 0; i < n; i++) {
    long long temp;
    char temp2;
    scanf("%lld-%c", &temp, &temp2);
    if (a.size() && a.back().second == temp2)
      a.back().first += temp;
    else
      a.push_back({temp, temp2});
  }
  for (int i = 0; i < m; i++) {
    long long temp;
    char temp2;
    scanf("%lld-%c", &temp, &temp2);
    if (b.size() && b.back().second == temp2)
      b.back().first += temp;
    else
      b.push_back({temp, temp2});
  }
  if (b.size() > a.size()) {
    cout << 0 << endl;
  } else if (b.size() == 1) {
    long long ans = 0;
    for (auto v : a)
      if (v.first >= b[0].first && v.second == b[0].second)
        ans += v.first - b[0].first + 1;
    cout << ans << endl;
  } else if (b.size() == 2) {
    long long ans = 0;
    for (int i = 0; i < a.size() - 1; i++) {
      if (a[i].first < b[0].first) continue;
      if (a[i].second != b[0].second) continue;
      if (a[i + 1].first < b[1].first) continue;
      if (a[i + 1].second != b[1].second) continue;
      ans++;
    }
    cout << ans << endl;
  } else {
    vector<long long> c, d;
    pair<long long, char> q = b[0], w = b[b.size() - 1];
    for (int i = 1; i < b.size() - 1; i++)
      c.push_back(b[i].first), d.push_back(b[i].second);
    c.push_back(-1);
    d.push_back(-1);
    for (int i = 0; i < a.size(); i++)
      c.push_back(a[i].first), d.push_back(a[i].second);
    vector<int> cc = prefix_function(c);
    vector<int> dd = prefix_function(d);
    long long ans = 0, len = b.size() - 2;
    for (int i = b.size() - 1 + len; i < c.size() - 1; i++) {
      if (cc[i] != len) continue;
      if (dd[i] != len) continue;
      if (d[i - len] != q.second || c[i - len] < q.first) continue;
      if (d[i + 1] != w.second || c[i + 1] < w.first) continue;
      ans++;
    }
    cout << ans << endl;
  }
  return;
}
int main() {
  int T;
  for (T = 1; T; T--) {
    solve();
  }
}
