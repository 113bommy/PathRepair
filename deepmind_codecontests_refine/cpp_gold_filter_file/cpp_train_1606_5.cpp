#include <bits/stdc++.h>
using namespace std;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
const double pi = 2 * asin(1.0);
int n;
int m;
int a[100010], b[100010];
vector<pair<int, pair<int, int> > > c;
map<int, pair<int, pair<int, int> > > e;
int d[3][100010];
int ansa[100010], ansb[100010];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i], &b[i]);
    c.push_back(make_pair(a[i], make_pair(1, i)));
    c.push_back(make_pair(b[i], make_pair(2, i)));
  }
  sort(c.begin(), c.end());
  for (int i = 0; i < ((int)(c).size()); i++) {
    d[c[i].second.first][c[i].second.second] = i;
  }
  int p = 0;
  while (p < n) {
    if (c[p].second.first == 1)
      ansa[c[p].second.second] = 1;
    else
      ansb[c[p].second.second] = 1;
    p++;
  }
  for (int i = 1; 2 * i <= n; i++) {
    ansa[i - 1] = 1;
    ansb[i - 1] = 1;
  }
  for (int i = 0; i < n; i++) printf("%d", ansa[i]);
  printf("\n");
  for (int i = 0; i < n; i++) printf("%d", ansb[i]);
  return 0;
}
