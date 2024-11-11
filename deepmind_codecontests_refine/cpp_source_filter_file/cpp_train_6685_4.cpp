#include <bits/stdc++.h>
bool debug = false;
using namespace std;
constexpr int kN = int(2E5 + 10);
int l[kN], r[kN], cnt[kN];
bool went[kN];
void solve() {
  int n, op = 0, ip = 0, ans = 0, tmp = 0, ladd = 0;
  bool f = false;
  queue<int> q;
  vector<int> x;
  vector<pair<int, int>> in, out;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
  for (int i = 1; i <= n; i++) cnt[i] = 0;
  for (int i = 1; i <= n; i++) went[i] = false;
  for (int i = 1; i <= n; i++) x.push_back(l[i]);
  for (int i = 1; i <= n; i++) x.push_back(r[i]);
  for (int i = 1; i <= n; i++) in.push_back({l[i], i});
  for (int i = 1; i <= n; i++) out.push_back({r[i], i});
  sort(in.begin(), in.end());
  sort(out.begin(), out.end());
  sort(x.begin(), x.end());
  x.resize(unique(x.begin(), x.end()) - x.begin());
  for (int i : x) {
    while (ip < in.size()) {
      if (in[ip].first <= i)
        q.push(in[ip++].second);
      else
        break;
    }
    f = false;
    if (ip - op >= 2) f = true;
    while (op < out.size()) {
      if (out[op].first <= i)
        went[out[op++].second] = true;
      else
        break;
    }
    if (debug)
      printf("i = %d, ip = %d, op = %d, f = %d\n", i, ip, op, f ? 1 : 0);
    if (ladd != 0 && ip - op == 0) cnt[ladd]--;
    ladd = 0;
    if (ip - op == 0)
      ans++;
    else if (ip - op == 1 && f) {
      while (!q.empty()) {
        if (went[q.front()])
          q.pop();
        else
          break;
      }
      cnt[q.front()]++;
      ladd = q.front();
    }
  }
  for (int i = 1; i <= n; i++) tmp = max(tmp, cnt[i]);
  if (ans + tmp == n) ans--;
  if (debug) printf("ans = %d, tmp = %d\n", ans, tmp);
  printf("%d\n", ans + tmp);
  return;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
}
