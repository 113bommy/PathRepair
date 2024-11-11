#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int> > d;
vector<int> ans;
int n, p, k, i, used[101010];
bool cmp(pair<pair<int, int>, int> b1, pair<pair<int, int>, int> b2) {
  return b1.first.second > b2.first.second ||
         (b1.first.second == b2.first.second &&
          b1.first.first > b2.first.first);
}
bool cmp2(pair<pair<int, int>, int> b1, pair<pair<int, int>, int> b2) {
  return b1.first.second > b2.first.second;
}
int main() {
  scanf("%d %d %d", &n, &p, &k);
  for (i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    d.push_back(make_pair(make_pair(a, b), i + 1));
  }
  sort(d.begin(), d.end(), cmp);
  int h = 0, v = 1111111111, m;
  for (i = n - 1; h < p - k; i--) used[d[i].second] = 2, h++;
  sort(d.begin(), d.end(), greater<pair<pair<int, int>, int> >());
  h = 0;
  for (i = 0; h < k; i++)
    if (!used[d[i].second]) {
      ans.push_back(d[i].second);
      used[d[i].second] = 1;
      if (v > d[i].first.second) v = d[i].first.second, m = 1111111111;
      h++;
      if (v == d[i].first.second) m = min(m, d[i].first.first);
    }
  sort(d.begin(), d.end(), cmp2);
  for (i = 0; ans.size() < p; i++)
    if (used[d[i].second] != 1 &&
        (d[i].first.second < v ||
         (d[i].first.second == v && d[i].first.first >= m)))
      ans.push_back(d[i].second);
  for (i = 0; i < p; i++) printf("%d ", ans[i]);
  return 0;
}
