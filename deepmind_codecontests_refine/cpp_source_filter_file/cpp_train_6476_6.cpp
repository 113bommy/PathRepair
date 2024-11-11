#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> Map;
vector<int> vec[400066], V;
int d[400066], f[400066];
int ans[400066];
bool check(int x, int y) { return x * y <= d[x]; }
int main() {
  scanf("%d", &n);
  int x;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    Map[x]++;
  }
  for (auto p : Map) vec[p.second].push_back(p.first);
  for (int i = n; i > 0; i--) f[i] = f[i + 1] + vec[i].size();
  for (int i = 1; i <= n; i++) d[i] = d[i - 1] + f[i];
  int a = 0, b = 0;
  for (int i = 1; i * i <= n; i++) {
    if (!check(i, i)) continue;
    int l = i, r = n / i + 1;
    while (r > l) {
      int mid = (l + r + 1) >> 1;
      if (check(i, mid))
        l = mid;
      else
        r = mid - 1;
    }
    if (i * l >= a * b) a = i, b = l;
  }
  printf("%d\n%d %d\n", a * b, a, b);
  int all = a * b;
  for (int i = n; i > 0; i--) {
    for (auto p : vec[i]) {
      int cnt = min(i, a);
      for (int j = 1; j <= cnt; j++) V.push_back(p);
    }
  }
  int p = 0;
  for (int i = 0; i < a * b; i++) {
    int x = i % a, y = (i % a + i / a) % b;
    ans[x * a + y] = V[p++];
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) printf("%d ", ans[i * a + j]);
    puts("");
  }
  return 0;
}
