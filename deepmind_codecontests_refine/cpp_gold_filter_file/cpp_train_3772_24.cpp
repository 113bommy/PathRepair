#include <bits/stdc++.h>
using namespace std;
int n, m, x[100001], y[100001], d[10];
set<int> c[200001], r[200001], d1[200001], d2[200001];
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x[i] >> y[i];
    c[x[i]].insert(y[i]);
    r[y[i]].insert(x[i]);
    d1[x[i] - y[i] + 100000].insert(x[i]);
    d2[x[i] + y[i]].insert(x[i]);
  }
  set<int>::iterator it1, it2;
  for (int i = 1; i <= m; i++) {
    int k = 0;
    if (c[x[i]].size() >= 2) {
      it1 = c[x[i]].begin(), it2 = c[x[i]].end(), it2--;
      if (*it1 < y[i]) k++;
      if (*it2 > y[i]) k++;
    }
    if (r[y[i]].size() >= 2) {
      it1 = r[y[i]].begin(), it2 = r[y[i]].end(), it2--;
      if (*it1 < x[i]) k++;
      if (*it2 > x[i]) k++;
    }
    if (d1[x[i] - y[i] + 100000].size() >= 2) {
      it1 = d1[x[i] - y[i] + 100000].begin(),
      it2 = d1[x[i] - y[i] + 100000].end(), it2--;
      if (*it1 < x[i]) k++;
      if (*it2 > x[i]) k++;
    }
    if (d2[x[i] + y[i]].size() >= 2) {
      it1 = d2[x[i] + y[i]].begin(), it2 = d2[x[i] + y[i]].end(), it2--;
      if (*it1 < x[i]) k++;
      if (*it2 > x[i]) k++;
    }
    d[k]++;
  }
  for (int i = 0; i <= 8; i++) cout << d[i] << " ";
  cout << endl;
  return 0;
}
