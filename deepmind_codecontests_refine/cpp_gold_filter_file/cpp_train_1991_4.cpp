#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
char trans['z' + 1];
int n, q;
char s[N];
struct tree {
  int a[N + 1];
  void add(int x, int s) {
    for (; x <= N; x += x & -x) a[x] += s;
  }
  int ask(int x) {
    int s = 0;
    for (; x >= 1; x -= x & -x) s += a[x];
    return s;
  }
} t[4];
set<int> S[4];
int tot[4], ma[4], mi[4];
void update() {
  for (int i = 1; i <= 3; ++i) ma[i] = *--S[i].lower_bound(1e9);
  for (int i = 1; i <= 3; ++i) mi[i] = *S[i].lower_bound(0);
}
int gmin(int x) { return mi[x]; }
int gmax(int x) { return ma[x]; }
int solve(int x, int y, int z) {
  int res = 0;
  if (!tot[y])
    res += tot[x];
  else if (tot[z]) {
    int l = gmin(z), r = gmax(z);
    if (l < r) res += t[x].ask(r) - t[x].ask(l);
    int L = gmin(y);
    res += t[x].ask(min(l, L));
    int R = gmax(y);
    res += tot[x] - t[x].ask(max(R, r));
  }
  return res;
}
void print() {
  int ans = 0;
  ans += solve(2, 3, 1);
  ans += solve(1, 2, 3);
  ans += solve(3, 1, 2);
  printf("%d\n", ans);
}
int main() {
  trans['R'] = '2';
  trans['S'] = '1';
  trans['P'] = '3';
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) s[i] = trans[s[i]];
  for (int i = 1; i <= 3; ++i) S[i].insert(1e9), S[i].insert(-1);
  for (int i = 1; i <= n; ++i) S[s[i] - '0'].insert(i);
  for (int i = 1; i <= n; ++i) t[s[i] - '0'].add(i, 1), tot[s[i] - '0']++;
  update();
  print();
  for (int i = 1; i <= q; ++i) {
    int x;
    char y;
    cin >> x >> y;
    y = trans[y];
    S[s[x] - '0'].erase(x);
    t[s[x] - '0'].add(x, -1);
    tot[s[x] - '0']--;
    s[x] = y;
    S[s[x] - '0'].insert(x);
    t[s[x] - '0'].add(x, 1);
    tot[s[x] - '0']++;
    update();
    print();
  }
}
