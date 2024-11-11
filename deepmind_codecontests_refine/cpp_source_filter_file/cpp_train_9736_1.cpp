#include <bits/stdc++.h>
int n, t, q;
int p[200003];
int l[200003];
int c[200003];
using pair = std::pair<double, int>;
using mset = std::multiset<pair>;
mset dat1, dat2;
double ans = 0;
void rem(int i) {
  double val = (double)c[i] / (c[i] + l[i]) * p[i];
  if (c[i] < l[i])
    dat1.erase(dat1.find(std::make_pair(
        (double)(c[i] + 1) / (c[i] + 1 + l[i]) * p[i] - val, i)));
  if (c[i] > 1)
    dat2.erase(dat2.find(std::make_pair(
        (double)(c[i] - 1) / (c[i] - 1 + l[i]) * p[i] - val, i)));
  ans -= val;
}
void add(int i) {
  double val = (double)c[i] / (c[i] + l[i]) * p[i];
  if (c[i] < l[i])
    dat1.insert(
        std::make_pair((double)(c[i] + 1) / (c[i] + 1 + l[i]) * p[i] - val, i));
  if (c[i] > 1)
    dat2.insert(
        std::make_pair((double)(c[i] - 1) / (c[i] - 1 + l[i]) * p[i] - val, i));
  ans += val;
}
int main() {
  scanf("%d%d%d", &n, &t, &q);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &l[i]);
  }
  {
    std::priority_queue<std::pair<double, int> > pq;
    for (int i = 0; i < n; ++i) {
      pq.emplace(((double)1 / (l[i] + 1)) * p[i], i);
    }
    while (t > 0 && !pq.empty()) {
      std::pair<double, int> cur = pq.top();
      pq.pop();
      int i = cur.second;
      ++c[i];
      if (c[i] < l[i])
        pq.emplace(((double)(c[i] + 1) / (c[i] + 1 + l[i]) -
                    (double)c[i] / (c[i] + l[i])) *
                       p[i],
                   i);
      --t;
    }
  }
  for (int i = 0; i < n; ++i) add(i);
  for (int j = 0; j < q; ++j) {
    int tt, i;
    scanf("%d%d", &tt, &i);
    --tt, --i;
    if (tt == 0) {
      rem(i);
      ++l[i];
      add(i);
    } else {
      rem(i);
      --l[i];
      if (c[i] > l[i]) {
        --c[i];
        ++t;
      };
      add(i);
    }
    while (t > 0 && !dat1.empty()) {
      mset::iterator cur = --dat1.end();
      int i = cur->second;
      rem(i);
      ++c[i];
      add(i);
      --t;
    }
    while (!dat1.empty() && !dat2.empty() &&
           dat1.rbegin()->first + dat2.rbegin()->first > 0) {
      mset::iterator cur1 = --dat1.end(), cur2 = --dat2.end();
      int i = cur1->second, j = cur2->second;
      rem(i);
      ++c[i];
      add(i);
      rem(j);
      --c[j];
      add(j);
    }
    printf("%.10f\n", ans);
  }
}
