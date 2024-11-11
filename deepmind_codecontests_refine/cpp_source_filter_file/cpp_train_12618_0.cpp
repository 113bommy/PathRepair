#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int> > svi;
bool svip;
vector<pair<int, pair<int, int> > > pp, pn, nn, np;
int main() {
  scanf("%d", &n);
  svip = true;
  for (int i = 1; i <= n; i++) {
    int t1, t2;
    scanf("%d %d", &t1, &t2);
    t1 = abs(t1 + 1000005), t2 = abs(t2 + 1000005);
    svi.push_back(make_pair((t1), (t2)));
  }
  while (true) {
    int broj = 1;
    pp.clear();
    np.clear();
    pn.clear();
    nn.clear();
    for (auto x : svi) {
      if (!(x.first & 1) && !(x.second & 1)) pp.push_back(make_pair(broj, x));
      if ((x.first & 1) && !(x.second & 1)) np.push_back(make_pair(broj, x));
      if (!(x.first & 1) && (x.second & 1)) pn.push_back(make_pair(broj, x));
      if ((x.first & 1) && (x.second & 1)) nn.push_back(make_pair(broj, x));
      broj++;
    }
    if (pp.size() + nn.size() > 0 && pp.size() + nn.size() < n) {
      printf("%d\n", pp.size() + nn.size());
      for (auto x : pp) printf("%d", x.first);
      for (auto x : nn) printf("%d ", x.first);
      return 0;
    }
    if (pp.size() + nn.size() == n && !pp.empty() && !nn.empty()) {
      printf("%d\n", pp.size());
      for (auto x : pp) printf("%d ", x.first);
      return 0;
    }
    if (!np.empty() && !pn.empty()) {
      printf("%d\n", np.size());
      for (auto x : np) printf("%d ", x.first);
      return 0;
    }
    for (int i = 0; i < svi.size(); i++) {
      svi[i].first /= 2;
      svi[i].second /= 2;
    }
  }
  return 0;
}
