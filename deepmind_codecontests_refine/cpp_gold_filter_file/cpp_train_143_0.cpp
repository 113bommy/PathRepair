#include <bits/stdc++.h>
using namespace std;
const int MAX_BUF_SIZE = 16384;
char BUFOR[MAX_BUF_SIZE];
int BUF_SIZE, BUF_POS;
char ZZZ;
int _MINUS;
const int MXN = 5010;
const int C = 262144;
const int INF = 1000000000;
int dx[MXN];
int n, m;
int res[MXN];
int resT[MXN];
void test() {
  scanf("%d %d", &n, &m);
  for (int i = (1); i <= (n); i++) res[i] = INF;
  vector<pair<pair<int, int>, pair<int, int> > > zap;
  for (int i = (1); i <= (m); i++) {
    int typ;
    scanf("%d", &typ);
    if (typ == 1) {
      int l, r, d;
      scanf("%d %d %d", &l, &r, &d);
      zap.push_back(make_pair(make_pair(l, r), make_pair(d, 1)));
      for (int j = (l); j <= (r); j++) dx[j] += d;
    } else {
      int l, r, m;
      scanf("%d %d %d", &l, &r, &m);
      zap.push_back(make_pair(make_pair(l, r), make_pair(m, 2)));
      for (int j = (l); j <= (r); j++) res[j] = min(res[j], m - dx[j]);
    }
  }
  for (int i = (1); i <= (n); i++) resT[i] = res[i];
  bool dec = 1;
  for (__typeof((zap).begin()) it = ((zap).begin()); it != (zap).end(); ++it) {
    int l, r, m;
    pair<int, int> p1 = it->first;
    l = p1.first;
    r = p1.second;
    m = (it->second).first;
    int typ = (*it).second.second;
    if (typ == 1) {
      for (int j = (l); j <= (r); j++) {
        resT[j] += m;
      }
    } else {
      int MX = -INF;
      for (int j = (l); j <= (r); j++) {
        MX = max(MX, resT[j]);
      }
      if (MX != m) dec = 0;
    }
  }
  printf(dec ? "YES\n" : "NO\n");
  if (dec) {
    for (int i = (1); i <= (n); i++) printf("%d ", res[i]);
  }
}
int main() {
  int te = 1;
  while (te--) test();
  return 0;
}
