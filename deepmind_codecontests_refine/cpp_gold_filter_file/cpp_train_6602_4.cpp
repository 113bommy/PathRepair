#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long int LINF = 0x3f3f3f3f3f3f3f3fll;
const long double pi = acos(-1);
const int MOD = 1e9 + 9;
int n, m;
vector<pair<int, int> > v;
set<pair<int, int> > resolve(set<pair<int, int> > &cur,
                             vector<pair<int, int> > &aux) {
  set<pair<int, int> > ret;
  set<pair<int, int> > aux2;
  int l = 1;
  for (pair<int, int> x : aux) {
    if (l <= x.second - 1) aux2.insert(make_pair(l, x.second - 1));
    l = x.second + 1;
  }
  if (l <= n) aux2.insert(make_pair(l, n));
  if (aux[0].first == 1) {
    if (1 <= aux[0].second - 1) ret.insert(make_pair(1, aux[0].second - 1));
    return ret;
  }
  for (pair<int, int> x : aux2) {
  }
  for (pair<int, int> x : cur) {
  }
  auto i = cur.begin();
  auto j = aux2.begin();
  while (i != cur.end() and j != aux2.end()) {
    if ((*j).first > (*i).second)
      i++;
    else if ((*j).second < (*i).first)
      j++;
    else {
      ret.insert(make_pair(max((*i).first, (*j).first), (*j).second));
      j++;
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    v.push_back(make_pair(x, y));
  }
  sort(v.begin(), v.end());
  set<pair<int, int> > cur;
  cur.insert(make_pair(1, n));
  int last = 0;
  for (int i = 0; i < m; i++) {
    if (v[i].first - last > 1) {
      pair<int, int> aux = *cur.begin();
      aux.second = n;
      cur.clear();
      cur.insert(aux);
    }
    last = v[i].first;
    int j = i;
    vector<pair<int, int> > aux;
    while (v[i].first == v[j].first and j < m) {
      aux.push_back(v[j]);
      j++;
    }
    i = j - 1;
    cur = resolve(cur, aux);
    if (cur.size() == 0) {
      cout << -1 << endl;
      return 0;
    }
  }
  bool ok = false;
  cerr << "cur.size()"
       << " == " << cur.size() << endl;
  for (pair<int, int> x : cur) {
    if (x.first <= x.second and x.second == n) ok = true;
  }
  if (last < n) ok = true;
  if (ok) {
    cout << 2 * n - 2 << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
