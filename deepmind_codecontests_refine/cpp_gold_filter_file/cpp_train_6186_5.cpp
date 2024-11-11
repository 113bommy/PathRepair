#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template <class T>
inline bool Min(T &a, T b) {
  return a > b ? (a = b, true) : false;
}
template <class T>
inline bool Max(T &a, T b) {
  return a < b ? (a = b, true) : false;
}
inline void pi(int a) { printf("%d ", a); }
inline void pl(ll a) { printf("%lld ", a); }
inline void pd(double a) { printf("%.12lf ", a); }
inline int ni() {
  int a;
  scanf("%d", &a);
  return a;
}
inline ll nl() {
  ll a;
  scanf("%lld", &a);
  return a;
}
inline double nd() {
  double a;
  scanf("%lf", &a);
  return a;
}
const int N = 2010;
int ver[N][N];
int hor[N][N];
char a[N][N];
int cnt = 0;
int n, m;
bool check(int i, int j, int l) {
  if (i < 0 or j < 0 or l > min(n, m) or i + l > n or j + l > m) return false;
  l--;
  int sum = 0;
  sum = ver[i + l][j] + ver[i + l][j + l] + hor[i][j + l - 1] +
        hor[i + l][j + l - 1];
  if (i) sum -= ver[i - 1][j] + ver[i - 1][j + l];
  sum -= hor[i][j] + hor[i + l][j];
  return sum == cnt;
}
void solve() {
  scanf("%d%d\n", &n, &m);
  for (int i = 0; i < (int)(n); ++i) scanf("%s\n", a[i]);
  int x = -1, y = -1;
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j)
      if (a[i][j] == 'w') {
        cnt++;
        ver[i][j]++;
        hor[i][j]++;
        x = i, y = j;
      }
  for (int i = 0; i < (int)(n); ++i)
    for (int j = 0; j < (int)(m); ++j) {
      if (i) ver[i][j] += ver[i - 1][j];
      if (j) hor[i][j] += hor[i][j - 1];
    }
  int X = x, Y = y;
  int ans = 0;
  if (cnt == 1)
    ans = 1;
  else
    ans = -1;
  for (int l = min(n, m); l > 1 and cnt > 1; l--) {
    for (int i = 0; i < (int)(n); ++i) {
      if (check(i, y, l)) X = i, Y = y, ans = l;
      if (check(i, y - l + 1, l)) X = i, Y = y - l + 1, ans = l;
    }
    for (int j = 0; j < (int)(m); ++j) {
      if (check(x, j, l)) X = x, Y = j, ans = l;
      if (check(x - l + 1, j, l)) X = x - l + 1, Y = j, ans = l;
    }
  }
  if (ans == -1) {
    cout << "-1";
    return;
  }
  for (int i = X; i < X + ans; i++)
    a[i][Y] = (a[i][Y] == 'w') ? 'w' : '+',
    a[i][Y + ans - 1] = (a[i][Y + ans - 1] == 'w') ? 'w' : '+';
  for (int j = Y; j < Y + ans; j++)
    a[X][j] = (a[X][j] == 'w') ? 'w' : '+',
    a[X + ans - 1][j] = (a[X + ans - 1][j] == 'w') ? 'w' : '+';
  for (int i = 0; i < (int)(n); ++i) printf("%s\n", a[i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand((int)clock());
  solve();
  return 0;
}
