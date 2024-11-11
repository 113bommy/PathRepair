#include <bits/stdc++.h>
using namespace std;
map<int, vector<pair<int, int> > > hr, vr;
struct node {
  int ind;
  bool is_hor;
  int value;
  vector<pair<int, int> > v;
};
void function_lel_it(vector<pair<int, int> > &v, vector<node> &n, bool is_hor,
                     int ind, int limit) {
  node nd;
  nd.value = limit;
  nd.ind = ind;
  nd.is_hor = is_hor;
  sort(v.begin(), v.end());
  int sz = 0;
  int cnt = 0;
  int last;
  nd.v.push_back(pair<int, int>(0, 0));
  for (int i = 0; i < v.size(); i++) {
    if (!cnt) {
      last = v[i].first;
    }
    cnt -= 2 * v[i].second - 1;
    if (!cnt) {
      nd.value -= (v[i].first - last), sz += (v[i].first - last);
      nd.v.push_back(pair<int, int>(v[i].first - sz, v[i].first));
    }
  }
  n.push_back(nd);
}
vector<node> vn;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int i1, i2, j1, j2;
    cin >> i1 >> j1 >> i2 >> j2;
    if (i1 == i2) {
      hr[i2].push_back(pair<int, int>(min(j1, j2), 0));
      hr[i2].push_back(pair<int, int>(max(j1, j2), 1));
    } else {
      vr[j1].push_back(pair<int, int>(min(i1, i2), 0));
      vr[j2].push_back(pair<int, int>(max(i1, i2), 1));
    }
  }
  int lr = n - 1 - vr.size();
  int lh = m - 1 - hr.size();
  if (lr & 1) {
    for (int i = 1; i < n; i++) {
      if (hr.find(i) == hr.end()) {
        hr[i];
        break;
      }
    }
  }
  if (lh & 1) {
    for (int i = 1; i < m; i++) {
      if (vr.find(i) == vr.end()) {
        vr[i];
        break;
      }
    }
  }
  for (auto &it : hr) {
    function_lel_it(it.second, vn, 1, it.first, n);
  }
  for (auto &it : vr) {
    function_lel_it(it.second, vn, 0, it.first, m);
  }
  int ret = 0;
  for (int i = 0; i < vn.size(); i++) {
    ret ^= vn[i].value;
  }
  cout << ((ret != 0) ? "FIRST" : "SECOND") << endl;
  if (ret == 0) return 0;
  int backup = ret;
  while ((backup & (backup - 1))) {
    backup -= (backup & (-backup));
  }
  int first;
  for (int i = 0; i < vn.size(); i++) {
    if (vn[i].value & backup) {
      first = i;
      break;
    }
  }
  int sheel = vn[first].value - (vn[first].value ^ ret);
  int ind = int(upper_bound(vn[first].v.begin(), vn[first].v.end(),
                            pair<int, int>(sheel, (1 << 30))) -
                vn[first].v.begin()) -
            1;
  int last = vn[first].v[ind].second + (sheel - (vn[first].v[ind].first));
  if (vn[first].is_hor) {
    cout << vn[first].ind << " " << 0 << " " << vn[first].ind << " " << last
         << endl;
  } else
    cout << 0 << " " << vn[first].ind << " " << last << " " << vn[first].ind
         << endl;
}
