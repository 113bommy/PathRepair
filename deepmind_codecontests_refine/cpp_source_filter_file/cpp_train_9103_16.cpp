#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double PI = acos(-1.);
const long long MOD = 1000000007;
vector<pair<int, int> > gao(int *x, int n, int *X, int *use, int &U, int &len) {
  int i, j, k;
  for (i = 0; i < n; i++) X[i] = x[i];
  int mx = *max_element(X, X + n);
  len = 0;
  while ((1LL << len) <= mx) len++;
  vector<pair<int, int> > ret;
  for (j = k = 0; k < len; k++) {
    int tmp = -1;
    for (i = j; i < n; i++)
      if (X[i] >> k & 1) {
        tmp = i;
        break;
      }
    use[k] = -1;
    if (tmp == -1) continue;
    if (tmp != j) {
      ret.push_back(make_pair(j, tmp));
      X[j] ^= X[tmp];
      ret.push_back(make_pair(tmp, j));
      X[tmp] ^= X[j];
      ret.push_back(make_pair(j, tmp));
      X[j] ^= X[tmp];
    }
    for (i = 0; i < n; i++)
      if (i != j)
        if (X[i] >> k & 1) {
          ret.push_back(make_pair(i, j));
          X[i] ^= X[j];
        }
    use[k] = j++;
  }
  U = j;
  return ret;
}
int x[10005], X[10005];
int y[10005], Y[10005];
int useX[66], useY[66];
int UX, UY, lenX, lenY;
int main() {
  int i, j, k, T;
  int n, U, len;
  while (~scanf("%d", &n)) {
    for (i = 0; i < n; i++) scanf("%d", &x[i]);
    for (i = 0; i < n; i++) scanf("%d", &y[i]);
    memset(useX, -1, sizeof useX);
    memset(useY, -1, sizeof useY);
    vector<pair<int, int> > px = gao(x, n, X, useX, UX, lenX);
    vector<pair<int, int> > py = gao(y, n, Y, useY, UY, lenY);
    map<int, int> mx, my;
    for (i = 0; i < lenY; i++)
      if (~useY[i]) my[useY[i]] = i;
    for (i = 0; i < lenX; i++)
      if (~useX[i]) mx[useX[i]] = i;
    int fail = 0;
    for (i = 0; i < lenY; i++)
      if (~useY[i])
        if (useX[i] == -1) fail = 1;
    for (i = 0; i < lenX; i++)
      if (~useX[i]) {
        if (useY[i] == -1) {
          int id = useX[i];
          for (j = 0; j < UY; j++)
            if (Y[j] >> id & 1) {
              int t = my[j];
              int s = useX[t];
              px.push_back(make_pair(s, id));
              X[s] ^= X[id];
            }
          px.push_back(make_pair(id, id));
          X[id] ^= X[id];
          useX[i] = -1;
        }
      }
    vector<int> tx, ty;
    for (i = 0; i < UX; i++)
      if (X[i]) tx.push_back(X[i]);
    for (i = 0; i < UY; i++)
      if (Y[i]) ty.push_back(Y[i]);
    sort(tx.begin(), tx.end());
    sort(ty.begin(), ty.end());
    if (tx.size() != ty.size())
      fail = 1;
    else {
      for (i = 0; i < tx.size(); i++)
        if (tx[i] != ty[i]) fail = 1;
    }
    for (i = 0; i < UY; i++) {
      for (j = i; j < UX; j++)
        if (X[j] == Y[i]) break;
      if (i != j) {
        px.push_back(make_pair(i, j));
        X[i] ^= X[j];
        px.push_back(make_pair(j, i));
        X[j] ^= X[i];
        px.push_back(make_pair(i, j));
        X[i] ^= X[j];
      }
    }
    for (i = py.size() - 1; i >= 0; i--) {
      int u = py[i].first;
      int v = py[i].second;
      px.push_back(make_pair(u, v));
      X[u] ^= X[v];
    }
    for (i = 0; i < n; i++)
      if (X[i] != y[i]) fail = 1;
    if (fail)
      printf("-1\n");
    else {
      printf("%d\n", px.size());
      for (i = 0; i < px.size(); i++)
        printf("%d %d\n", px[i].first + 1, px[i].second + 1);
    }
  }
  return 0;
}
