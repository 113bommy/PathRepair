#include <bits/stdc++.h>
using namespace std;
const int Maxn = 300005, Maxm = 100005, Mo = 1000000007,
          step[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
const long long oo = INT_MAX >> 2;
struct Tree {
  int x, y;
};
struct edge {
  int v, c, w, Ft;
};
struct point {
  long long x, y;
};
typedef int IArr[Maxn];
typedef long long LArr[Maxn];
typedef double DArr[Maxn];
int n, m, i, s1, s2;
LArr f;
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (i = 1; i <= n; i++) {
    int a;
    cin >> a;
    if (a == 1) s1++;
  }
  f[1] = f[0] = 1;
  f[2] = 2;
  for (int i = 3; i <= s1; i++) f[i] = (f[i - 1] + (i - 1) * f[i - 2]) % Mo;
  long long tmp = 1;
  for (i = s1 + 1; i <= n; i++) tmp = tmp * i % Mo;
  cout << f[s1] * tmp % Mo << endl;
}
