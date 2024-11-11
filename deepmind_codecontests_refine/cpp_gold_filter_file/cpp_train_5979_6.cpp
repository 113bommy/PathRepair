#include <bits/stdc++.h>
using namespace std;
const int N = 50050;
int n, m;
struct {
  int x, y, l;
} V[N], H[N];
struct data {
  int x, y1, y2, type;
  data(int _x, int _y1, int _y2, int _type) {
    x = _x;
    y1 = _y1;
    y2 = _y2;
    type = _type;
  }
};
bool cmp(const data& A, const data& B) {
  if (A.x != B.x) return A.x < B.x;
  return A.type < B.type;
}
bool solve(int Rad) {
  vector<data> Query;
  for (int i = 1; i <= n; ++i)
    if (V[i].l >= 2 * Rad)
      Query.push_back(data(V[i].x, V[i].y + Rad, V[i].y + V[i].l - Rad, 2));
  for (int i = 1; i <= m; ++i)
    if (H[i].l >= 2 * Rad) {
      Query.push_back(data(H[i].x + Rad, H[i].y, 0, 1));
      Query.push_back(data(H[i].x + H[i].l - Rad, H[i].y, 0, 3));
    }
  sort(Query.begin(), Query.end(), cmp);
  multiset<int> ms;
  for (int i = 0; i < Query.size(); ++i) {
    if (Query[i].type == 1)
      ms.insert(Query[i].y1);
    else if (Query[i].type == 3)
      ms.erase(ms.find(Query[i].y1));
    else {
      auto it1 = ms.lower_bound(Query[i].y1);
      auto it2 = ms.lower_bound(Query[i].y2 + 1);
      if (it1 != it2) return 1;
    }
  }
  return 0;
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> V[i].x >> V[i].y >> V[i].l;
  for (int i = 1; i <= m; ++i) cin >> H[i].x >> H[i].y >> H[i].l;
  int L = 0, R = 2e9 + 1, mid;
  while (L < R) {
    mid = (L + R) / 2;
    if (solve(mid))
      L = mid + 1;
    else
      R = mid;
  }
  if (L > 0 && !solve(L)) --L;
  cout << L;
}
