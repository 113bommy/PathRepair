#include <bits/stdc++.h>
using namespace std;
vector<int> vecK, vecV, vecO;
int pd[76][76][76][2], K = 0, V = 0, O = 0, x;
int movingcost(int v, int k, int o, int p) {
  int cnt = 0;
  for (; k < vecK.size() && vecK[k] < p; k++) cnt++;
  for (; o < vecO.size() && vecO[o] < p; o++) cnt++;
  for (; v < vecV.size() && vecV[v] < p; v++) cnt++;
  return cnt;
}
int go(int v = 0, int k = 0, int o = 0, int lv = 0, int p = 0) {
  if (p == x) return 0;
  int a, b, c;
  if (~pd[v][k][o][lv]) return pd[v][k][o][lv];
  pd[v][k][o][lv] = 1e9;
  if (o < O) {
    int cost = go(v, k, o + 1, 0, p + 1) + movingcost(v, k, o, vecO[o]);
    a = cost;
    pd[v][k][o][lv] = min(cost, pd[v][k][o][lv]);
  }
  if (v < V) {
    int cost = go(v + 1, k, o, 1, p + 1) + movingcost(v, k, o, vecV[v]);
    b = cost;
    pd[v][k][o][lv] = min(cost, pd[v][k][o][lv]);
  }
  if (k < K && !lv) {
    int cost = go(v, k + 1, o, 0, p + 1) + movingcost(v, k, o, vecK[k]);
    c = cost;
    pd[v][k][o][lv] = min(cost, pd[v][k][o][lv]);
  }
  return pd[v][k][o][lv];
}
int main() {
  memset(pd, -1, sizeof pd);
  string s;
  cin >> x >> s;
  for (int i = 0, __ = s.size(); i < __; ++i) {
    if (s[i] == 'V') {
      vecV.push_back(i);
      V++;
    } else if (s[i] == 'K') {
      vecK.push_back(i);
      K++;
    } else {
      vecO.push_back(i);
      O++;
    }
  }
  cout << (go()) << endl;
}
