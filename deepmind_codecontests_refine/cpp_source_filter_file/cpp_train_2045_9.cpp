#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, a[N];
vector<pair<vector<int>, vector<int> > > ans, two, thr;
inline pair<vector<int>, vector<int> > unite(
    pair<vector<int>, vector<int> > x, pair<vector<int>, vector<int> > y) {
  x.first.insert(x.first.begin(), y.first.begin(), y.first.end());
  x.second.insert(x.second.begin(), y.second.begin(), y.second.end());
  return x;
}
inline void split(pair<vector<int>, vector<int> > x) {
  pair<vector<int>, vector<int> > a1, a2;
  a1.first.push_back(x.first[0]);
  a1.first.push_back(x.first[1]);
  a1.second.push_back(x.first[1]);
  a1.second.push_back(x.first[0]);
  a2.first.push_back(x.first[0]);
  a2.first.push_back(x.first[2]);
  a2.second.push_back(x.first[2]);
  a2.second.push_back(x.first[0]);
  two.push_back(a1);
  two.push_back(a2);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++)
    while (a[i] != i) {
      int v = i;
      vector<int> tmp;
      tmp.push_back(v);
      while ((int)tmp.size() < 5 && a[v] != i) {
        v = a[v];
        tmp.push_back(v);
      }
      vector<int> tmans;
      for (int i = 0; i < (int)tmp.size(); i++)
        tmans.push_back(tmp[(i + 1) % (int)tmp.size()]);
      if ((int)tmp.size() == 2)
        two.push_back({tmp, tmans});
      else if ((int)tmp.size() == 3)
        thr.push_back({tmp, tmans});
      else
        ans.push_back({tmp, tmans});
      for (int i = (int)tmp.size() - 1; i > 0; i--)
        swap(a[tmp[i]], a[tmp[(i + 1) % (int)tmp.size()]]);
    }
  while ((int)thr.size()) {
    if ((int)two.size()) {
      ans.push_back(unite(two.back(), thr.back()));
      two.pop_back();
      thr.pop_back();
      continue;
    }
    if ((int)thr.size() == 1) {
      ans.push_back(thr[0]);
      thr.pop_back();
      continue;
    }
    split(thr.back());
    thr.pop_back();
  }
  while ((int)two.size()) {
    if ((int)two.size() == 1) {
      ans.push_back(two.back());
      two.pop_back();
      break;
    }
    pair<vector<int>, vector<int> > tmp = two.back();
    two.pop_back();
    ans.push_back(unite(tmp, two.back()));
    two.pop_back();
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) {
    printf("%d\n", (int)ans[i].first.size());
    for (int j = 0; j < (int)ans[i].first.size(); j++)
      printf("%d ", ans[i].first[j]);
    printf("\n");
    for (int j = 0; j < (int)ans[i].second.size(); j++)
      printf("%d ", ans[i].second[j]);
    printf("\n");
  }
  return 0;
}
