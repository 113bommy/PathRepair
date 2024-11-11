#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int a[N];
int b[N];
int delta[N][N];
int undef;
void fail() {
  printf("NO\n");
  exit(0);
}
struct Query {
  int t, l, r, res;
  Query(int t = 0, int l = 0, int r = 0, int res = 0) {
    this->t = t;
    this->l = l;
    this->r = r;
    this->res = res;
  }
};
vector<Query> queries;
int n, m;
const bool D = 0;
int main() {
  if (D) {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
  } else {
  }
  memset(a, 0x7F, sizeof(a));
  undef = a[0];
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int t, l, r, res;
    scanf("%d%d%d%d", &t, &l, &r, &res);
    queries.push_back(Query(t, l, r, res));
    if (i != 0)
      for (int j = 1; j <= n; ++j) delta[i][j] = delta[i - 1][j];
    if (t == 1) {
      for (int j = l; j <= r; ++j) delta[i][j] += res;
    } else {
      for (int j = l; j <= r; ++j) {
        a[j] = min(a[j], res - delta[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (a[i] == undef) a[i] = 0;
    b[i] = a[i];
  }
  for (vector<Query>::iterator i = queries.begin(); i != queries.end(); ++i) {
    if (i->t == 1) {
      for (int j = i->l; j <= i->r; ++j) b[j] += i->res;
    } else {
      int cmax = (-(int)1e9) - 1;
      for (int j = i->l; j <= i->r; ++j) cmax = max(cmax, b[j]);
      if (cmax != i->res) {
        fail();
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
  printf("\n");
  return 0;
}
