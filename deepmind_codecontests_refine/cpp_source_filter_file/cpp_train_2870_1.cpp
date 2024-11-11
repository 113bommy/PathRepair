#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;
struct node {
  int x;
  int y;
};
bool cmp(node p, node q) { return p.x < q.x; }
node a[MAXN];
int main() {
  int n, m, r, l;
  cin >> n >> m;
  vector<int> res(n);
  int mex = INT_MAX;
  for (int i = 0; i < m; i++) {
    cin >> a[i].x >> a[i].y;
    mex = min(mex, a[i].y - a[i].x + 1);
  }
  for (int i = 0; i < m; i++) {
    res[i] = i % mex;
  }
  cout << mex << endl;
  for (int x : res) cout << x << " ";
  cout << endl;
  return 0;
}
