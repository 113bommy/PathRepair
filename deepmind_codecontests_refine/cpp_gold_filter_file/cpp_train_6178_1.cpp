#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
int n;
int m;
int p[200];
int was[200];
vector<pair<int, int> > res;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) p[i] = -1;
  int k = 0;
  for (int i = 0; i < m; i++) {
    int t;
    scanf("%d", &t);
    for (int j = 0; j < t; j++) {
      int x;
      scanf("%d", &x);
      x--;
      p[x] = k++;
    }
  }
  int f = 0;
  for (int i = 0; i < n; i++)
    if (p[i] == -1) f = i;
  memset(was, 0, sizeof(was));
  for (int i = k; i < n; i++)
    if (p[i] != -1) {
      vector<int> v;
      int j = i;
      while (j != -1) {
        was[j] = 1;
        v.push_back(j);
        j = p[j];
      }
      for (int t = ((int)(v).size()) - 2; t >= 0; t--) {
        res.push_back(make_pair(v[t], v[t + 1]));
        if (v[t + 1] == f) f = v[t];
      }
    }
  for (int i = 0; i < k; i++)
    if (!was[i] && p[i] != -1 && p[i] != i) {
      vector<int> v;
      int j = i;
      do {
        was[j] = 1;
        v.push_back(j);
        j = p[j];
      } while (j != i);
      int of = f;
      res.push_back(make_pair(v[((int)(v).size()) - 1], f));
      f = v[((int)(v).size()) - 1];
      for (int t = ((int)(v).size()) - 2; t >= 0; t--) {
        res.push_back(make_pair(v[t], v[t + 1]));
        if (v[t + 1] == f) f = v[t];
      }
      res.push_back(make_pair(of, v[0]));
      f = of;
    }
  printf("%d\n", ((int)(res).size()));
  for (int i = 0; i < ((int)(res).size()); i++)
    printf("%d %d\n", res[i].first + 1, res[i].second + 1);
  return 0;
}
