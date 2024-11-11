#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int logo = 20;
const int off = 1 << logo;
const int siz = off << 1;
const int inf = 0x3f3f3f3f;
int n, m, k, q;
pair<int, int> niz[maxn];
pair<pair<int, int>, int> qs[maxn];
vector<pair<pair<int, int>, int> > events;
int qm[maxn][4];
bool sol[maxn];
int tourmax[siz], tourmin[siz];
int querymin(int a, int b, int l, int r, int nod) {
  if (r < a || l > b) return inf;
  if (a <= l && b >= r) {
    return tourmin[nod];
  }
  int mid = (l + r) / 2;
  return min(querymin(a, b, l, mid, nod * 2),
             querymin(a, b, mid + 1, r, nod * 2 + 1));
}
void updatemin(int indx, int val) {
  indx += off;
  tourmin[indx] = val;
  indx /= 2;
  while (indx > 0)
    tourmin[indx] = min(tourmin[indx * 2], tourmin[indx * 2 + 1]), indx /= 2;
}
int querymax(int a, int b, int l, int r, int nod) {
  if (r < a || l > b) return 0;
  if (a <= l && b >= r) {
    return tourmax[nod];
  }
  int mid = (l + r) / 2;
  return max(querymax(a, b, l, mid, nod * 2),
             querymax(a, b, mid + 1, r, nod * 2 + 1));
}
void updatemax(int indx, int val) {
  indx += off;
  tourmax[indx] = val;
  indx /= 2;
  while (indx > 0)
    tourmax[indx] = max(tourmax[indx * 2], tourmax[indx * 2 + 1]), indx /= 2;
}
int main() {
  memset(sol, false, sizeof sol);
  scanf("%d%d%d%d", &n, &m, &k, &q);
  for (int i = 0; i < k; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    niz[i] = make_pair(a, b);
  }
  for (int i = 0; i < q; i++)
    for (int j = 0; j < 4; j++) scanf("%d", &qm[i][j]);
  for (int i = 0; i < k; i++) {
    events.push_back(make_pair(niz[i], -1));
  }
  for (int i = 0; i < q; i++) {
    events.push_back(make_pair(make_pair(qm[i][2], qm[i][3]), i));
  }
  sort(events.begin(), events.end());
  memset(tourmax, inf, sizeof tourmax);
  memset(tourmin, inf, sizeof tourmin);
  for (int i = 0; i < events.size(); i++) {
    if (events[i].second == -1) {
      updatemax(events[i].first.second, events[i].first.first);
      updatemin(events[i].first.second, events[i].first.first);
    } else {
      int tren = events[i].second;
      if (querymax(qm[tren][1], qm[tren][3], 0, off - 1, 1) < inf &&
          querymin(qm[tren][1], qm[tren][3], 0, off - 1, 1) >= qm[tren][0])
        sol[tren] = true;
    }
  }
  events.clear();
  for (int i = 0; i < k; i++) {
    swap(niz[i].first, niz[i].second);
    events.push_back(make_pair(niz[i], -1));
  }
  for (int i = 0; i < q; i++) {
    events.push_back(make_pair(make_pair(qm[i][3], qm[i][2]), i));
  }
  sort(events.begin(), events.end());
  memset(tourmax, inf, sizeof tourmax);
  memset(tourmin, inf, sizeof tourmin);
  for (int i = 0; i < events.size(); i++) {
    if (events[i].second == -1) {
      updatemax(events[i].first.second, events[i].first.first);
      updatemin(events[i].first.second, events[i].first.first);
    } else {
      int tren = events[i].second;
      if (querymax(qm[tren][0], qm[tren][2], 0, off - 1, 1) < inf &&
          querymin(qm[tren][0], qm[tren][2], 0, off - 1, 1) >= qm[tren][1])
        sol[tren] = true;
    }
  }
  for (int i = 0; i < q; i++) {
    if (sol[i])
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
