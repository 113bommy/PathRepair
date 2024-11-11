#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const double eps = 1e-15;
const double pi = acos(-1.0);
const int MAXN = (int)1e6 + 7;
const int INF = (long long)1e9 + 7;
const long long LINF = (long long)4e18;
const int MOD = (long long)1e9 + 7;
const int CNT = 10000;
int solve();
int main() {
  solve();
  return 0;
}
struct pt {
  int x, y, num;
};
vector<pt> a;
vector<int> ans;
bool cmp(pt &p1, pt &p2) {
  return p1.x < p2.x || (p1.x == p2.x && ((p1.x & 1) ^ (p1.y < p2.y)));
}
int solve() {
  int n;
  scanf("%d", &n);
  int x, y;
  for (int i = 0; i < (int)n; i++) {
    scanf("%d%d", &x, &y);
    a.push_back({x / CNT, y, i + 1});
  }
  sort(a.begin(), a.end(), cmp);
  for (pt p : a) {
    printf("%d ", p.num);
  }
  return 0;
}
