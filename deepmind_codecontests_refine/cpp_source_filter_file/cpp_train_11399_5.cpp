#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
map<int, int> mk;
int a, uy, b, c, n, m, T[2][100007 * 8], po;
char type[100007 * 8];
pair<long long, long long> d[100007 * 8];
vector<int> v;
set<int> s;
void nh() {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  for (int i = 0; i < int(v.size()); i++) mk[v[i]] = i + 1;
  po = int(v.size());
}
void find(int x, int l, int r, int v, int w) {
  uy = max(uy, T[w][v]);
  if (l == r) return;
  if (x <= (l + r) / 2)
    find(x, l, (l + r) / 2, v * 2, w);
  else
    find(x, (l + r) / 2 + 1, r, v * 2 + 1, w);
}
void upd(int x, int y, int l, int r, int v, int w, int z) {
  if (x > r || y < l) return;
  if (x <= l && r <= y) {
    T[w][v] = max(T[w][v], z);
    return;
  }
  upd(x, y, l, (l + r) / 2, v * 2, w, z);
  upd(x, y, (l + r) / 2 + 1, r, v * 2 + 1, w, z);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> d[i].first >> d[i].second >> type[i];
    v.push_back(d[i].first), v.push_back(d[i].second);
  }
  nh();
  for (int i = 1; i <= m; i++) {
    uy = 0;
    if (s.count(d[i].second)) {
      cout << "0" << endl;
      continue;
    }
    if (type[i] == 'U') {
      find(mk[d[i].first], 1, po + 1, 1, 0);
      cout << d[i].second - uy << endl;
      upd(mk[uy] + 1, mk[d[i].second], 1, po + 1, 1, 1, d[i].first);
    } else {
      find(mk[d[i].second], 1, po + 1, 1, 1);
      cout << d[i].first - uy << endl;
      upd(mk[uy] + 1, mk[d[i].first], 1, po + 1, 1, 0, d[i].second);
    }
    s.insert(d[i].second);
  }
  return 0;
}
