#include <bits/stdc++.h>
using namespace std;
void rf() {}
const int nx[8] = {2, -2, -2, 2, 1, 1, -1, -1};
const int ny[8] = {1, 1, -1, -1, 2, -2, -2, 2};
const int Nx[4] = {0, 0, -1, 1};
const int Ny[4] = {1, -1, 0, 0};
const long long LINF = (long long)5e18;
const int INF = 1e9 + 7;
const int N = 2e3 + 123;
const int MAXN = 1e6 + 50;
const double EPS = 1e-9, PI = 3.14159265359;
int n, m, k, Q;
vector<pair<pair<int, int>, int> > v[N];
struct query {
  int id, t, x, y, x1, kjdajasjdsas;
  void norm() {
    if (x > x1) swap(x, x1);
    if (y > kjdajasjdsas) swap(y, kjdajasjdsas);
  }
};
query a[MAXN];
long long t[N][N];
inline void upd(const int &x, const int &y, const int &w) {
  for (int i = x - 1; i < n; i = (i | (i + 1)))
    for (int j = y - 1; j < n; j = (j | (j + 1))) t[i][j] += w;
}
inline long long g(const int &x, const int &y) {
  long long second = 0;
  for (int i = x - 1; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y - 1; j >= 0; j = (j & (j + 1)) - 1) second += t[i][j];
  return second;
}
inline long long get(const int &x, const int &y, const int &x1,
                     const int &kjdajasjdsas) {
  return g(x1, kjdajasjdsas) - g(x - 1, kjdajasjdsas) - g(x1, y - 1) +
         g(x - 1, y - 1);
}
long long ans[N][N];
bool bad[N];
int main() {
  srand(time(0));
  rf();
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1, len; i <= k; i++) {
    scanf("%d", &len);
    while (len--) {
      int x, y, w;
      scanf("%d%d%d", &x, &y, &w);
      v[i].push_back(make_pair(make_pair(x, y), w));
    }
  }
  scanf("%d", &Q);
  vector<query> t;
  int c = 0;
  for (int i = 1; i <= Q; i++) {
    char buff[10];
    scanf("\n%s", &buff);
    if (buff[0] == 'S') {
      a[i].t = 1;
      scanf("%d", &a[i].x);
    } else {
      a[i].t = 2;
      scanf("%d%d%d%d", &a[i].x, &a[i].y, &a[i].x1, &a[i].kjdajasjdsas);
      a[i].id = ++c;
      a[i].norm();
      t.push_back(a[i]);
    }
  }
  for (int i = 1; i <= k; i++) {
    for (auto it : t) ans[i][it.id] -= get(it.x, it.y, it.x1, it.kjdajasjdsas);
    for (auto it : v[i]) upd(it.first.first, it.first.second, it.second);
    for (auto it : t) ans[i][it.id] += get(it.x, it.y, it.x1, it.kjdajasjdsas);
  }
  for (int i = 1; i <= Q; i++) {
    if (a[i].t == 1) {
      bad[a[i].x] ^= 1;
    } else {
      long long cur_ans = 0;
      for (int j = 1; j <= k; j++) {
        if (!bad[j]) cur_ans += ans[j][a[i].id];
      }
      printf("%I64d\n", cur_ans);
    }
  }
  return 0;
}
