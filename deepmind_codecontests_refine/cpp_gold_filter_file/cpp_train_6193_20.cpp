#include <bits/stdc++.h>
using namespace std;
char f(const pair<long long, long long> &a, const pair<long long, long long> &b,
       const pair<long long, long long> &c) {
  return (c.second - a.second) * (c.first - b.first) * a.first * b.second <
         (c.first - a.first) * (c.second - b.second) * a.second * b.first;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, long long> > p(n);
  for (pair<long long, long long> &i : p) {
    scanf("%I64d%I64d", &i.first, &i.second);
  }
  vector<pair<long long, long long> > P = p, ch;
  p.emplace_back(0, 1e4 + 1);
  p.emplace_back(1e4 + 1, 0);
  sort((p).begin(), (p).end());
  for (auto i : p) {
    while (ch.size() > 1 && (ch.back().second == i.second ||
                             f(ch[(ch.size() - 2)], ch.back(), i))) {
      ch.pop_back();
    }
    ch.push_back(i);
  }
  for (int i = 0; i < n; ++i)
    if (binary_search((ch).begin(), (ch).end(), P[i])) {
      printf("%d ", i + 1);
    }
  return 0;
}
