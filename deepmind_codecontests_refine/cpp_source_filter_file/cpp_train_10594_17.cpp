#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
using pii = pair<int, int>;
pii x;
vector<pii> a;
vector<pii> b;
map<pair<int, int>, int> m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  for (int i = 0; i < 4; i++) {
    cin >> x.first >> x.second;
    a.push_back(x);
  }
  for (int i = 0; i < 4; i++) {
    cin >> x.first >> x.second;
    b.push_back(x);
  }
  sort(a.begin(), a.end(), [](const pii &q, const pii &w) { return q < w; });
  sort(b.begin(), b.end(), [](const pii &q, const pii &w) { return q < w; });
  int top1 = a[1].second;
  int top2 = a[2].first;
  for (int i = a[0].first; i <= top1; i++)
    for (int o = a[0].second; o <= top2; o++) {
      m[make_pair(i, o)] = 1;
    }
  pair<int, int> top = b[2];
  int cnt = 0;
  for (pair<int, int> i = b[0]; i <= top; i.first++, i.second++) {
    if (m.count(i)) return 0 * puts("YES");
    if (i == top) {
      cnt++;
      i.first = b[0].first + cnt;
      i.second = b[0].second - cnt;
      i.first--;
      i.second--;
      top.first++;
      top.second--;
      if (i.first + 1 > b[1].first) break;
    }
  }
  return 0 * puts("NO");
}
