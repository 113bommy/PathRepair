#include <bits/stdc++.h>
using namespace std;
int n, a, b, p[100005], f[100005], v[100005], flag[100005];
map<int, int> mp;
int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); }
void Union(int x, int y) {
  int rx = Find(x), ry = Find(y);
  if (rx == ry) return;
  f[rx] = ry;
}
int main() {
  int i;
  scanf("%d%d%d", &n, &a, &b);
  for (i = 0; i < (n); i++) {
    scanf("%d", &p[i]);
    mp[p[i]] = i;
    f[i] = i;
    v[i] = 0;
    flag[i] = 3;
  }
  for (i = 0; i < (n); i++) {
    if (mp.find(a - p[i]) != mp.end()) {
      Union(mp[a - p[i]], i);
      v[i] |= 1;
    }
    if (mp.find(b - p[i]) != mp.end()) {
      Union(mp[b - p[i]], i);
      v[i] |= 2;
    }
  }
  for (i = 0; i < (n); i++) flag[Find(i)] &= v[i];
  for (i = 0; i < (n); i++) {
    if (flag[i] == 0) {
      puts("NO");
      return 0;
    }
  }
  puts("YES");
  for (i = 0; i < (n); i++) {
    if (flag[Find(i)] & 1)
      printf("0 ");
    else
      printf("1 ");
  }
  puts("");
  return 0;
}
