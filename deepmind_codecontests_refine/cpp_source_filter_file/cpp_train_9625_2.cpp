#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
const int mlen = 800;
vector<pair<int, int> > v;
vector<pair<int, int> > use;
int get(pair<int, int> x) {
  return ((x.first) * (x.first)) + ((x.second) * (x.second));
}
bool l1(pair<int, int> a, pair<int, int> b) { return get(a) < get(b); }
bool l2(int a, int b) { return v[a].first > v[b].first; }
bool l3(int a, int b) { return v[a].second > v[b].second; }
bool l4(int a, int b) {
  double tmp = atan2(v[a].first, v[a].second) - atan2(v[b].first, v[b].second);
  if (abs(tmp) > 1e-8) {
    return tmp > 0;
  } else
    return get(v[a]) > get(v[b]);
}
int id[10000], ox[1000], oy[1000];
int main() {
  cin >> n;
  for (int x = 1; x <= min(mlen, n + 2); x++)
    for (int y = 0; y < (x + 1); y++) v.push_back(make_pair(x, y));
  sort((v).begin(), (v).end(), l1);
  vector<pair<int, int> > vv;
  vv.push_back(v[0]);
  for (int i = 1; i < ((int)(v).size()); i++)
    if (get(v[i]) != get(v[i - 1])) vv.push_back(v[i]);
  v = vv;
  int sx, sy;
  sx = sy = 0;
  for (int i = 0; i < (n); i++) {
    sx += v[i].first;
    sy += v[i].second;
  }
  if (sx % 2 && sy % 2) {
    swap(v[0].first, v[0].second);
  } else if (sx % 2 || sy % 2) {
    sx += v[n].first;
    sy += v[n].second;
    if (sx % 2 && sy % 2) swap(v[n], v[1]);
    if (sx % 2 && sy % 2 == 0) swap(v[n], v[0]);
    if (sx % 2 == 0 && sy % 2) swap(v[n], v[3]);
    if (sx % 2 == 0 && sy % 2 == 0) swap(v[n], v[2]);
  }
  for (int i = 0; i < (n); i++) id[i] = i;
  sort(id, id + n, l2);
  int cx = 0;
  for (int i = 0; i < (n); i++) {
    if (cx <= 0)
      ox[id[i]] = 1;
    else
      ox[id[i]] = -1;
    cx += ox[id[i]] * v[id[i]].first;
  }
  for (int i = 0; i < (n); i++) id[i] = i;
  sort(id, id + n, l3);
  int cy = 0;
  for (int i = 0; i < (n); i++) {
    if (cy <= 0)
      oy[id[i]] = 1;
    else
      oy[id[i]] = -1;
    cy += oy[id[i]] * v[id[i]].second;
  }
  for (int i = 0; i < (n); i++) {
    v[i].first *= ox[i];
    v[i].second *= oy[i];
  }
  for (int i = 0; i < (n); i++) id[i] = i;
  sort(id, id + n, l4);
  cx = cy = 0;
  cout << "YES" << endl;
  for (int i = 0; i < (n); i++) {
    cout << cx << ' ' << cy << endl;
    cx += v[id[i]].first;
    cy += v[id[i]].second;
  }
  return 0;
}
