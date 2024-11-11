#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<long long, long long>, int> > v, v1;
vector<pair<pair<long long, long long>, int> > cht;
map<long long, long long> my;
int c[200011] = {0};
vector<pair<long long, long long> > r;
set<long long> second;
bool intersection(int l1, int l2, int l3) {
  long long p1 = (cht[l2].first.second * cht[l3].first.first *
                  (cht[l3].first.second - cht[l1].first.second) *
                  (cht[l1].first.first - cht[l2].first.first));
  long long p2 = (cht[l3].first.second * cht[l2].first.first *
                  (cht[l2].first.second - cht[l1].first.second) *
                  (cht[l1].first.first - cht[l3].first.first));
  int p;
  if (p1 < p2)
    p = 1;
  else
    p = 0;
  return p;
}
void add(long long m, long long b, int i) {
  cht.push_back(make_pair(make_pair(m, b), i));
  while (cht.size() > 2 &&
         intersection(cht.size() - 3, cht.size() - 2, cht.size() - 1))
    cht.erase(cht.end() - 2);
}
int main() {
  int i, j, n, n1;
  cin >> n;
  n1 = n;
  for (i = 0; i < n; i++) {
    long long r1, s1;
    cin >> s1 >> r1;
    r.push_back(make_pair(s1, r1));
    v1.push_back(make_pair(make_pair(s1, r1), i + 1));
  }
  sort(v1.begin(), v1.end());
  for (int i = 0; i < n; i++) {
    while (!v.empty() && v.back().first.second <= v1[i].first.second)
      v.pop_back();
    v.push_back(v1[i]);
  }
  n = v.size();
  for (i = 0; i < n; i++) add(v[i].first.first, v[i].first.second, v[i].second);
  for (i = 0; i < cht.size(); i++) {
    c[cht[i].second] = 1;
    my[cht[i].first.first] = cht[i].first.second;
  }
  for (i = 0; i < n; i++)
    if (c[i + 1] == 0 && my.find(r[i].first) != my.end() &&
        my[r[i].first] == r[i].second)
      c[i + 1] = 1;
  for (i = 1; i <= n1; i++)
    if (c[i] == 1) printf("%d ", i);
  return 0;
}
