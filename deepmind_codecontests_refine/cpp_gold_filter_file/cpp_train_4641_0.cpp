#include <bits/stdc++.h>
using namespace std;
const int nmax = 2e5;
int last[nmax + 1], ans[nmax + 1];
bool viz[nmax + 1];
pair<int, int> v[nmax + 1];
vector<pair<int, int> > w;
vector<pair<int, int> > ce[nmax + 1];
vector<int> aux;
int main() {
  int n;
  fscanf(stdin, "%d", &n);
  for (int i = 1; i <= n; ++i) {
    fscanf(stdin, "%d%d", &v[i].first, &v[i].second);
  }
  for (int i = n; i > 0; --i) {
    if (viz[v[i].first] == 0) {
      viz[v[i].first] = 1;
      w.push_back(make_pair(i, v[i].first));
    }
  }
  w.push_back(make_pair(0, 0));
  memset(viz, 0, sizeof(viz));
  int q;
  fscanf(stdin, "%d", &q);
  for (int i = 1; i <= q; ++i) {
    for (auto j : aux) viz[j] = 0;
    aux.clear();
    int k;
    fscanf(stdin, "%d", &k);
    for (int j = 0; j < k; ++j) {
      int x;
      fscanf(stdin, "%d", &x);
      viz[x] = 1;
      aux.push_back(x);
    }
    int ind = 0;
    while (ind < (int)w.size() && viz[w[ind].second] == 1) {
      ++ind;
    }
    int ind2 = ind + 1;
    while (ind2 < (int)w.size() && viz[w[ind2].second] == 1) {
      ++ind2;
    }
    if (ind2 < (int)w.size() && ind < (int)w.size()) {
      ce[w[ind2].first].push_back(make_pair(w[ind].second, i));
    }
  }
  for (int i = n; i >= 0; --i) {
    for (auto j : ce[i]) {
      ans[j.second] = last[j.first];
    }
    last[v[i].first] = i;
  }
  for (int i = 1; i <= q; ++i) {
    fprintf(stdout, "%d %d\n", v[ans[i]].first, v[ans[i]].second);
  }
  return 0;
}
