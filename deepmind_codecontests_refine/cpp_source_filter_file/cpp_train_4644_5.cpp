#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long linf = (long long)1e18;
const double eps = (double)1e-8;
const int mod = (int)1e9 + 7;
const int maxn = (int)1e6 + 5;
int BITS = 3;
int k[maxn];
int a[maxn][2];
int cnt;
void add(int x) {
  int v = 1;
  int p;
  for (int i = (BITS); i >= (int)(-1); --i) {
    ++k[v];
    if (i == -1) break;
    if (x & (1 << i))
      p = 1;
    else
      p = 0;
    if (a[v][p] == 0) {
      k[cnt] = 0;
      a[cnt][0] = 0;
      a[cnt][1] = 0;
      a[v][p] = cnt++;
    }
    v = a[v][p];
  }
}
void del(int x) {
  int v = 1;
  int p;
  for (int i = (BITS); i >= (int)(-1); --i) {
    --k[v];
    if (i == -1) break;
    if (x & (1 << i))
      p = 1;
    else
      p = 0;
    v = a[v][p];
  }
}
int dzen(int p, int l) {
  int ans = 0;
  int v = 1;
  for (int i = (BITS); i >= (int)(0); --i) {
    if (v == 0) break;
    if (p & (1 << i)) {
      if (l & (1 << i)) {
        ans += k[a[v][1]];
        v = a[v][0];
      } else {
        v = a[v][1];
      }
    } else {
      if (l & (1 << i)) {
        ans += k[a[v][0]];
        v = a[v][1];
      } else {
        v = a[v][0];
      }
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  k[0] = 0;
  a[1][0] = 0;
  a[1][1] = 0;
  cnt = 2;
  int n;
  cin >> n;
  for (int i = (1); i <= (int)(n); ++i) {
    int typ, x;
    cin >> typ >> x;
    if (typ == 1) add(x);
    if (typ == 2) del(x);
    if (typ == 3) {
      int y;
      cin >> y;
      cout << dzen(x, y) << "\n";
    }
  }
  return 0;
}
