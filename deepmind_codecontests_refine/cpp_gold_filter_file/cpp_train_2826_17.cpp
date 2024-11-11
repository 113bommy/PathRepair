#include <bits/stdc++.h>
using namespace std;
int n, m;
int p[100055];
int s[100055];
int b[100055];
int inc[100055];
int pref[100055];
vector<int> in[300055], out[300055];
vector<int> query[300055];
int datl[200055];
int datr[200055];
int res[100055];
void add(int *dat, int id, int val) {
  while (id < n + m) {
    dat[id] += val;
    id |= (id + 1);
  }
}
int get(int *dat, int id) {
  int res = 0;
  while (id >= 0) {
    res += dat[id];
    id = (id & (id + 1)) - 1;
  }
  return res;
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &s[i]);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &inc[i]);
  }
  for (int i = 0; i < m; i++) {
    scanf("%d", &pref[i]);
  }
  {
    vector<int> vec;
    for (int i = 0; i < n; i++) {
      vec.push_back(p[i]);
      vec.push_back(s[i]);
    }
    for (int i = 0; i < m; i++) {
      vec.push_back(inc[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 0; i < n; i++) {
      int l = lower_bound(vec.begin(), vec.end(), p[i]) - vec.begin();
      int r = lower_bound(vec.begin(), vec.end(), s[i]) - vec.begin();
      in[l].push_back(i);
      out[r].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      int id = lower_bound(vec.begin(), vec.end(), inc[i]) - vec.begin();
      query[id].push_back(i);
    }
  }
  vector<int> vx;
  vector<int> vy;
  for (int i = 0; i < n; i++) {
    vx.push_back(p[i] + b[i]);
    vy.push_back(p[i] - b[i]);
  }
  for (int i = 0; i < m; i++) {
    vx.push_back(inc[i] + pref[i]);
    vy.push_back(inc[i] - pref[i]);
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  vx.erase(unique(vx.begin(), vx.end()), vx.end());
  vy.erase(unique(vy.begin(), vy.end()), vy.end());
  int cur = 0;
  for (int i = 0; i < n + n + m; i++) {
    for (auto id : in[i]) {
      int x = p[id] + b[id];
      int y = p[id] - b[id];
      x = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
      y = lower_bound(vy.begin(), vy.end(), y) - vy.begin();
      cur++;
      add(datl, x, 1);
      add(datr, y, -1);
    }
    for (auto id : query[i]) {
      int x = inc[id] + pref[id];
      int y = inc[id] - pref[id];
      x = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
      y = lower_bound(vy.begin(), vy.end(), y) - vy.begin();
      res[id] = get(datl, x) + (-cur - get(datr, y));
    }
    for (auto id : out[i]) {
      int x = p[id] + b[id];
      int y = p[id] - b[id];
      cur--;
      x = lower_bound(vx.begin(), vx.end(), x) - vx.begin();
      y = lower_bound(vy.begin(), vy.end(), y) - vy.begin();
      add(datl, x, -1);
      add(datr, y, 1);
    }
  }
  for (int i = 0; i < m; i++) printf("%d ", res[i]);
}
