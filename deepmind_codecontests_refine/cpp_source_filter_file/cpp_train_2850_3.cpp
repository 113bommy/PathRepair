#include <bits/stdc++.h>
using namespace std;
int n, m, k, mas;
int s[200000], ks, re[200000];
bool bi[2000000];
vector<int> kr;
pair<pair<int, int>, pair<int, pair<bool, int> > > sa[400000];
int main() {
  priority_queue<pair<int, int>, vector<pair<int, int> >,
                 greater<pair<int, int> > >
      qq;
  cin >> n >> m;
  int k = 0;
  for (int i = 0; i < 2 * m; ++i) {
    cin >> sa[i].first.first >> sa[i].first.second >> sa[i].second.first;
    s[sa[i].first.first] += sa[i].second.first;
    s[sa[i].first.second] += sa[i].second.first;
    sa[i].second.second.second = k;
    ++i;
    sa[i].first.first = sa[i - 1].first.second;
    sa[i].first.second = sa[i - 1].first.first;
    sa[i].second.first = sa[i - 1].second.first;
    sa[i].second.second.first = 1;
    sa[i].second.second.second = k++;
  }
  for (int i = 0; i < n; ++i) s[i] = s[i] >> 1;
  sort(sa, sa + 2 * m);
  int pr = 1;
  pair<int, int> t;
  t.first = 0;
  t.second = 1;
  qq.push(t);
  while (!qq.empty()) {
    pair<int, int> t = qq.top();
    qq.pop();
    while (bi[t.second]) {
      if (qq.empty()) break;
      t = qq.top();
      qq.pop();
    }
    pr = t.second;
    bi[pr] = 1;
    int l = 0, r = 2 * m - 1, mi, mid;
    while (l <= r) {
      mi = (l + r) >> 1;
      if (sa[mi].first.first >= pr)
        r = mi - 1;
      else
        l = mi + 1;
      if (sa[mi].first.first == pr) mid = mi;
    }
    while (sa[mid].first.first == pr && mid < 2 * m) {
      if (bi[sa[mid].first.second]) {
        mid++;
        continue;
      }
      s[sa[mid].first.second] -= sa[mid].second.first;
      pair<int, int> t;
      t.first = s[sa[mid].first.second];
      t.second = sa[mid].first.second;
      if (t.second != n) qq.push(t);
      re[sa[mid].second.second.second] = sa[mid].second.second.first;
      mid++;
    }
  }
  for (int i = 0; i < m; ++i) cout << re[i] << endl;
}
