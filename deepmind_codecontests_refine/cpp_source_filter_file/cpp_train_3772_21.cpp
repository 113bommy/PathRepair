#include <bits/stdc++.h>
using namespace std;
int n, m;
int c[466666], res[100];
vector<pair<int, int> > v[466666], g[466666], d1[466666], d2[466666];
void pl(int i) { c[i]++; }
void relax(vector<pair<int, int> > a) {
  if (a.size() == 1) return;
  for (int k = 0; k < a.size(); k++) {
    if (k == 0) {
      pl(a[0].second);
    } else if (k == a.size() - 1) {
      pl(a[a.size() - 1].second);
    } else {
      pl(a[k].second);
      pl(a[k].second);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int r, c;
    scanf("%d%d", &r, &c);
    v[r].push_back(make_pair(c, i));
    g[c].push_back(make_pair(r, i));
    d1[r - c + 222222].push_back(make_pair(c, i));
    d2[r + c].push_back(make_pair(c, i));
  }
  for (int i = 0; i < 466666; i++) {
    sort(v[i].begin(), v[i].end());
    sort(g[i].begin(), g[i].end());
    sort(d1[i].begin(), d1[i].end());
    sort(d2[i].begin(), d2[i].end());
    relax(v[i]);
    relax(g[i]);
    relax(d1[i]);
    relax(d2[i]);
  }
  for (int i = 0; i < m; i++) {
    res[c[i]]++;
  }
  for (int i = 0; i < 8; i++) {
    printf("%d ", res[i]);
  }
  return 0;
}
