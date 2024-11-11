#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > v;
int ar1[2009];
int ar2[2009];
int ar3[2009];
int main() {
  int xa, ya, xb, yb;
  cin >> xa >> ya >> xb >> yb;
  for (int i = min(xa, xb); i <= max(xb, xb); i++) {
    for (int j = min(ya, yb); j <= max(ya, yb); j++) {
      if (i == xa || i == xb || j == ya || j == yb)
        v.push_back(pair<int, int>(i, j));
    }
  }
  v.erase(unique(v.begin(), v.end()), v.end());
  int c = 0;
  int n;
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    int x, y, r;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &r);
    ar1[i] = x;
    ar2[i] = y;
    ar3[i] = r;
  }
  for (int i = 0; i < v.size(); i++) {
    int x = v[i].first;
    int y = v[i].second;
    int safe = 0;
    for (int j = 0; j < n; j++) {
      int t1 = ar1[j];
      int t2 = ar2[j];
      int r = ar3[j];
      if (((t1 - x) * (t1 - x) + (t2 - y) * (t2 - y)) <= r * r) {
        safe = 1;
        break;
      }
    }
    if (!safe) c++;
  }
  printf("%d\n", c);
}
