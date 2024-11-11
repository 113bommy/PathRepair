#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2005, Maxm = 200010, Mo = 1000000007, oo = INT_MAX;
struct Edge {
  int u, v;
};
typedef int IArr[Maxn];
IArr use, cnt, rge, x, y, mp[Maxn];
int T, i, j, k, n, l, r, pos, dir;
long long ans;
vector<pair<pair<int, int>, int> > G;
int main() {
  ios::sync_with_stdio(0);
  cin >> n >> k;
  if (n * (n - 1) / 2 < k) {
    cout << "no solution\n";
    return 0;
  }
  int x = -1000000000;
  int y = -x;
  for (i = 1; i <= n; i++) {
    cout << x << " " << y << endl;
    x++;
    y -= 2000;
  }
}
