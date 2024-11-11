#include <bits/stdc++.h>
using namespace std;
int n, Luck[100050], a[100050], near[100050], tot;
unsigned long long sum, ans, bad;
vector<int> vec[100050], luck;
map<int, vector<int> > add;
set<int> se, used;
bool check(int w) {
  while (w) {
    if (w % 10 != 4 && w % 10 != 7) return 0;
    w /= 10;
  }
  return 1;
}
long long calc(int x, int y) { return (y - x - 1) * (y - x) / 2; }
long long calb(int x, int y, int pos) {
  long long ret = 0, cnt = 0;
  for (register int i = x; i <= y; ++i) ret += 1ll * (++cnt) * (i - pos);
  return ret;
}
void ins(int x, int rr) {
  int pos = luck[rr - 1];
  rr = luck[rr];
  if (used.find(x) != used.end()) return;
  used.insert(x);
  for (auto v : add[x]) {
    if (v >= rr) continue;
    int up = *se.lower_bound(v), down = *--se.lower_bound(v);
    sum -= calc(down, up), sum += calc(down, v), sum += calc(v, up),
        se.insert(v);
    if (up == rr) bad = calb(pos + 1, rr - 1, v);
  }
}
int main() {
  scanf("%d", &n);
  luck.push_back(0);
  for (register int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (check(a[i])) {
      Luck[i] = 1, luck.push_back(i);
      if (add.find(a[i]) == add.end()) add[a[i]] = vec[++tot];
      add[a[i]].push_back(i);
    }
  }
  int nxt = n + 1;
  for (register int i = n; i; --i) nxt = Luck[i] ? i : nxt, near[i] = nxt;
  for (register int i = 1; i < luck.size(); ++i) {
    int u = luck[i];
    se.clear(), se.insert(0), se.insert(u), used.clear(), sum = 0;
    sum = calc(0, u), bad = calb(luck[i - 1] + 1, luck[i] - 1, 0);
    se.insert(0), se.insert(u);
    for (register int j = i; j < luck.size(); ++j) {
      if (j != i)
        ans += (luck[j] - luck[j - 1]) * (sum * (luck[i] - luck[i - 1]) - bad);
      ins(a[luck[j]], i);
    }
    ans +=
        (sum * (luck[i] - luck[i - 1]) - bad) * (n + 1 - luck[luck.size() - 1]);
  }
  for (register int i = 1; i <= n; ++i)
    ans += 1ll * (near[i] - i) * (i - 1) * (i) / 2;
  cout << ans << endl;
  return 0;
}
