#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
int n, m;
struct BIT {
  int c[maxn];
  void add(int x, int y) {
    for (; x <= n; x += (x & (-x))) c[x] += y;
  }
  int ask(int x) {
    int ans = 0;
    for (; x; x -= (x & (-x))) ans += c[x];
    return ans;
  }
  int query(int l, int r) { return ask(r) - ask(l - 1); }
};
BIT b[3];
set<int> s[3];
map<char, int> mp;
int a[maxn];
char str[maxn];
int solve(void) {
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    if (s[(i + 1) % 3].empty()) {
      ans += s[i].size();
      continue;
    }
    if (s[(i + 2) % 3].empty()) continue;
    int l1 = *(s[(i + 1) % 3].begin()), r1 = *(--s[(i + 1) % 3].end());
    ans += b[i].query(l1, r1);
    int l2 = *(s[(i + 2) % 3].begin()), r2 = *(--s[(i + 2) % 3].end());
    ans += b[i].query(1, min(l1, l2) - 1);
    ans += b[i].query(max(r1, r2) + 1, n);
  }
  return ans;
}
int main() {
  mp['R'] = 0, mp['P'] = 1, mp['S'] = 2;
  scanf("%d%d", &n, &m);
  scanf("%s", str + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = mp[str[i]];
    b[a[i]].add(i, 1);
    s[a[i]].insert(i);
  }
  printf("%d\n", solve());
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d%s", &x, str + 1);
    b[a[x]].add(x, -1);
    s[a[x]].erase(x);
    a[x] = mp[str[1]];
    b[a[x]].add(x, 1);
    s[a[x]].insert(x);
    printf("%d\n", solve());
  }
}
