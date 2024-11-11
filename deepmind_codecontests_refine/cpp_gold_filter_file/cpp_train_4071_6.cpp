#include <bits/stdc++.h>
using namespace std;
const int N = 3e3 + 10;
int num[N], cnt[N];
struct Node {
  int first, vis;
  long long c;
  Node(int first = 0, long long c = 0, int vis = 0)
      : first(first), c(c), vis(vis) {}
} p[N];
inline bool cmp1(Node &a, Node &b) {
  if (a.vis == 1) return false;
  if (b.vis == 1) return true;
  return a.c < b.c;
}
inline bool cmp2(Node &a, Node &b) {
  if (num[a.first] != num[b.first]) return num[a.first] > num[b.first];
  return a.c < b.c;
}
int n = 0, m, tot = 0;
long long f(int first) {
  for (int i = 0; i < n; ++i) p[i].vis = 0;
  long long sum = 0, ans = 0;
  memset(cnt, 0, sizeof cnt);
  sort(p, p + n, cmp2);
  for (int i = 2; i < m + 1; ++i)
    if (num[i] && num[i] >= first) cnt[i] = num[i] - first + 1, sum += cnt[i];
  for (int i = 0; i < n; ++i) {
    if (cnt[p[i].first]) {
      cnt[p[i].first]--;
      ans += p[i].c;
      p[i].vis = 1;
    }
  }
  first -= tot;
  first -= sum;
  if (first > 0) {
    sort(p, p + n, cmp1);
    for (int i = 0; i < first; ++i) ans += p[i].c;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0);
  memset(num, 0, sizeof num);
  int nn;
  cin >> nn >> m;
  int first, c;
  for (int i = 0; i < nn; ++i) {
    cin >> first >> c;
    if (first == 1) {
      tot++;
      continue;
    }
    p[n].first = first;
    p[n].c = c;
    num[p[n].first]++;
    p[n++].vis = 0;
  }
  int End = (n + 1) / 2 + 2;
  long long ans = f(tot);
  for (int i = tot + 1; i < End; ++i) ans = min(f(i), ans);
  cout << ans << endl;
}
