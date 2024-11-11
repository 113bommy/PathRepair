#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int MAX = 1000;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
int n, m;
struct re {
  int a, t;
} a[maxn];
map<int, int> fa;
bool cmp(re a, re b) { return a.t > b.t; }
int find(int k) {
  if (fa[k] == 0) fa[k] = k;
  if (fa[k] == k) return k;
  return fa[k] = find(fa[k]);
}
void unite(int x, int y) {
  int fay = find(y), fax = find(x);
  fa[fax] = fa[fay];
}
signed main() {
  int n;
  cin >> n;
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &a[i].a);
  }
  for (int i = (1); i <= (n); ++i) {
    scanf("%d", &a[i].t);
  }
  sort(a + 1, a + 1 + n, cmp);
  long long ans = 0;
  for (int i = (1); i <= (n); ++i) {
    int now = find(a[i].a);
    ans += (now - a[i].a) * a[i].t;
    unite(now, now + 1);
  }
  cout << (ans) << endl;
}
