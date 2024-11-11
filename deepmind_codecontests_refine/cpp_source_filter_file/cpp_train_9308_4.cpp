#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, x, y, xa[N], ya[N], xb[N], yb[N], a[N][N];
inline void f(vector<pair<int, pair<int, int> > > &vec) {
  sort(vec.begin(), vec.end());
  vector<pair<int, pair<int, int> > > q;
  for (int i = 0; i < vec.size(); i++) {
    if (!q.empty() && q.back().first == vec[i].first &&
        vec[i].second.first <= q.back().second.second) {
      q.back().second.second = vec[i].second.second;
    } else {
      q.push_back(vec[i]);
    }
  }
  vec = q;
}
inline bool intersect(pair<int, pair<int, int> > a,
                      pair<int, pair<int, int> > b) {
  return (a.second.first <= b.first && b.first <= a.second.second) &&
         (b.second.first <= a.first && a.first <= b.second.second);
}
inline bool check(int val) {
  vector<pair<int, pair<int, int> > > qa, qb;
  val += val;
  for (int i = 1; i <= n; i++) {
    qa.push_back(make_pair(xa[i], make_pair(ya[i] - val, ya[i] + val)));
  }
  for (int i = 1; i <= m; i++) {
    qb.push_back(make_pair(yb[i], make_pair(xb[i] - val, xb[i] + val)));
  }
  f(qa);
  f(qb);
  memset(a, 0, sizeof(a));
  for (int i = 0; i < qa.size(); i++) {
    vector<int> cur;
    for (int j = 0; j < qb.size(); j++) {
      if (intersect(qa[i], qb[j])) {
        for (int it : cur) {
          a[it][j]++;
          if (a[it][j] == 2) {
            return true;
          }
        }
        cur.push_back(j);
      }
    }
  }
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> xa[i] >> ya[i];
    x = xa[i], y = ya[i];
    xa[i] = x + y, ya[i] = x - y;
  }
  for (int i = 1; i <= m; i++) {
    cin >> xb[i] >> yb[i];
    x = xb[i], y = yb[i];
    xb[i] = x + y, yb[i] = x - y;
  }
  int l = 0, r = 1e8;
  while (r - l > 1) {
    int mid = (r + l) >> 1;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  if (check(l)) {
    cout << l;
  } else if (check(r)) {
    cout << r;
  } else {
    cout << "Poor Sereja";
  }
}
