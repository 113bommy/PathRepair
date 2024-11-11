#include <bits/stdc++.h>
using namespace std;
int n;
int k;
vector<vector<int> > lis;
vector<vector<int> > lismint;
int cnt[50002];
set<pair<int, int> > mp;
bool win(int id1, int id2) {
  for (int i = 0; i < k; i++) {
    if (lis[id1][i] > lismint[id2][i]) {
      return true;
    }
  }
  return false;
}
bool lose(int id1, int id2) {
  for (int i = 0; i < k; i++) {
    if (lismint[id1][i] < lis[id2][i]) {
      return true;
    }
  }
  return false;
}
int get_id(int val) {
  auto k = mp.lower_bound({val, INT_MAX});
  k--;
  return (*k).second;
}
void merge(int a, int b) {
  for (int i = 0; i < k; i++) {
    lis[a][i] = max(lis[a][i], lis[b][i]);
    lismint[a][i] = min(lismint[a][i], lismint[b][i]);
  }
  cnt[a] += cnt[b];
}
void output() {
  int ans = cnt[mp.rbegin()->second];
  printf("%d\n", ans);
}
int main() {
  for (int i = 0; i < 50002; i++) {
    cnt[i] = 1;
  }
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < k; j++) {
      int s;
      scanf("%d", &s);
      v.push_back(s);
    }
    lis.push_back(v);
    lismint.push_back(v);
    if (mp.size() == 0) {
      mp.insert(make_pair(v[0], i));
      output();
      continue;
    }
    if (win(lis.size() - 1, (*mp.begin()).second) == false) {
      mp.insert(make_pair(v[0], i));
      output();
      continue;
    }
    if (lose(lis.size() - 1, (*mp.rbegin()).second) == false) {
      mp.insert(make_pair(v[0], i));
      output();
      continue;
    }
    int mint = (*mp.begin()).first;
    int maxt = (*mp.rbegin()).first;
    while (mint + 1 < maxt) {
      int mid = (mint + maxt) >> 1;
      if (win(lis.size() - 1, get_id(mid))) {
        mint = mid;
      } else {
        maxt = mid;
      }
    }
    if (win(lis.size() - 1, get_id(maxt))) {
      mint = maxt;
    } else {
      maxt = mint;
    }
    int rngup = maxt;
    mint = (*mp.begin()).first;
    maxt = (*mp.rbegin()).first;
    while (mint + 1 < maxt) {
      int mid = (mint + maxt) >> 1;
      if (lose(lis.size() - 1, get_id(mid))) {
        maxt = mint;
      } else {
        mint = maxt;
      }
    }
    if (lose(lis.size() - 1, get_id(mint))) {
      maxt = mint;
    } else {
      mint = maxt;
    }
    int rngdw = mint;
    auto it = mp.lower_bound(make_pair(rngdw, INT_MAX));
    it--;
    while (it != mp.end() && (*it).first <= rngup) {
      auto nex = next(it);
      merge(lis.size() - 1, (*it).second);
      mp.erase(it);
      it = nex;
    }
    mp.insert(make_pair(lis.back()[0], lis.size() - 1));
    output();
  }
  return 0;
}
