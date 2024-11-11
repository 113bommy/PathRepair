#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > opt;
int n, a[1010];
pair<int, int> cpos;
void operate(int x, int y) {
  a[y] += a[x];
  a[x] = 0;
  opt.push_back(make_pair(x, y));
}
pair<int, int> solve(int x, int y, int z) {
  if (a[x] > a[y]) swap(x, y);
  if (a[y] > a[z]) swap(y, z);
  if (a[x] > a[y]) swap(x, y);
  if (a[y] > a[z]) swap(y, z);
  if (!a[x]) return make_pair(y, z);
  if (a[x] == a[y]) {
    operate(x, y);
    return make_pair(y, z);
  }
  if (a[y] == a[z]) {
    operate(y, z);
    return make_pair(x, z);
  }
  int q = a[y] / a[x];
  for (int i = 0; (1 << i) <= q; i++) {
    if ((q >> i) & 1)
      operate(x, y);
    else
      operate(x, z);
  }
  return solve(x, y, z);
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), cnt += a[i] != 0;
  if (cnt < 2) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != 0) {
      if (cpos.first == 0)
        cpos.first = i;
      else {
        cpos.second = i;
        break;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (i != cpos.first && i != cpos.second) {
      cpos = solve(i, cpos.first, cpos.second);
    }
  }
  printf("%d\n", opt.size());
  for (auto &x : opt) printf("%d %d\n", x.first, x.second);
  return 0;
}
