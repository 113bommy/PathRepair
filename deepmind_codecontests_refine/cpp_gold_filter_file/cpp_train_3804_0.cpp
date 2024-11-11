#include <bits/stdc++.h>
using namespace std;
map<int, int> tmap, valmap;
int t[1000005];
int val[1000005];
int q[1000005][3];
vector<int> v[1000005];
int bit[1000005];
vector<int> aff;
void add(int idx, int val, int n) {
  while (idx <= n) {
    bit[idx] += val;
    aff.push_back(idx);
    idx += (idx & (-idx));
  }
}
int sum(int idx) {
  int ans = 0;
  while (idx > 0) {
    ans += bit[idx];
    idx -= (idx & (-idx));
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (3); j++) scanf("%d", &q[i][j]);
    tmap[q[i][1]] = 0;
    valmap[q[i][2]] = 0;
  }
  int cnt = 1;
  for (map<int, int>::iterator it = tmap.begin(); it != tmap.end(); it++) {
    it->second = cnt;
    t[cnt++] = it->first;
  }
  cnt = 0;
  for (map<int, int>::iterator it = valmap.begin(); it != valmap.end(); it++) {
    it->second = cnt;
    val[cnt++] = it->first;
  }
  for (int i = 0; i < (n); i++) {
    v[valmap[q[i][2]]].push_back(i);
  }
  vector<int> ans(n, -1);
  int pos, typ, tpos;
  for (int i = 0; i < (n); i++) {
    for (int j = 0; j < (aff.size()); j++) {
      bit[aff[j]] = 0;
    }
    aff.clear();
    for (int j = 0; j < (v[i].size()); j++) {
      pos = v[i][j];
      typ = q[pos][0];
      tpos = tmap[q[pos][1]];
      if (typ == 1) {
        add(tpos, 1, n);
      } else if (typ == 2) {
        add(tpos, -1, n);
      } else {
        ans[pos] = sum(tpos);
      }
    }
  }
  for (int i = 0; i < (n); i++) {
    if (ans[i] != -1) printf("%d\n", ans[i]);
  }
  return 0;
}
