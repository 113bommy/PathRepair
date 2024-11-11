#include <bits/stdc++.h>
using namespace std;
bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
  if (a.first != b.first)
    return a.first < b.first;
  else
    return a.second > b.second;
}
long long dis(const pair<int, int> &a, const pair<int, int> &b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  int n;
  scanf("%d", &n);
  map<int, vector<pair<int, int> > > v;
  for (int i = 0; i < n; i++) {
    int first, second;
    scanf("%d %d", &first, &second);
    v[max(first, second)].push_back(make_pair((first), (second)));
  }
  pair<long long, pair<int, int> > l, r;
  l = r = make_pair((0), (make_pair((0), (0))));
  for (auto it : v) {
    sort(it.second.begin(), it.second.end(), cmp);
    long long add = dis(it.second.back(), it.second.front());
    pair<long long, pair<int, int> > templ =
        make_pair((add + min(l.first + dis(l.second, it.second.back()),
                             r.first + dis(r.second, it.second.back()))),
                  (it.second.front()));
    pair<long long, pair<int, int> > tempr =
        make_pair((add + min(l.first + dis(l.second, it.second.front()),
                             r.first + dis(r.second, it.second.front()))),
                  (it.second.back()));
    l = templ;
    r = tempr;
  }
  printf("%lld\n", min(l.first, r.first));
}
