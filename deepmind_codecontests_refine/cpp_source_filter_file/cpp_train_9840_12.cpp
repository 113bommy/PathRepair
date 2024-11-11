#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, a[N], b[N];
long long sa[N], sb[N];
vector<int> va[N], vb[N];
vector<int> ta, tb;
bool vis[N], flag = 0;
pair<int, int> pre[N];
void output() {
  if (flag) swap(ta, tb);
  printf("%d\n", ta.size());
  for (int i : ta) printf("%d ", i);
  printf("\n%d\n", tb.size());
  for (int i : tb) printf("%d ", i);
  exit(0);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), va[a[i]].push_back(i);
  for (int i = 1; i <= n; ++i) scanf("%d", b + i), vb[b[i]].push_back(i);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; ++i)
    sa[i] = sa[i - 1] + a[i], sb[i] = sb[i - 1] + b[i];
  if (sa[n] < sb[n]) {
    flag = 1;
    swap(sa, sb), swap(a, b), swap(va, vb);
  }
  for (int i = 1, it = 0; i <= n && it <= n; ++i) {
    vis[a[i]] = 1;
    while (it < n && sa[i] >= sb[it + 1] && sa[i] - sb[it + 1] <= n) ++it;
    if (sa[i] - sb[it + 1] > n) break;
    if (sa[i] == sb[it]) {
      for (int j = 1; j <= i; ++j)
        ta.push_back(va[a[j]].back()), va[a[j]].pop_back();
      for (int j = 1; j <= it; ++j)
        tb.push_back(vb[b[j]].back()), vb[b[j]].pop_back();
      output();
    }
    if (sb[it] && vis[sa[i] - sb[it]]) {
      bool ok = 0;
      for (int j = 1; j <= i; ++j)
        if (a[j] == sa[i] - sb[it] && !ok)
          ok = 1;
        else
          ta.push_back(va[a[j]].back()), va[a[j]].pop_back();
      for (int j = 1; j <= it; ++j)
        tb.push_back(vb[b[j]].back()), vb[b[j]].pop_back();
      output();
    }
    if (pre[sa[i] - sb[it]].first) {
      for (int j = pre[sa[i] - sb[it]].first + 1; j <= i; ++j)
        ta.push_back(va[a[j]].back()), va[a[j]].pop_back();
      for (int j = pre[sa[i] - sb[it]].second + 1; j <= it; ++j)
        tb.push_back(vb[b[j]].back()), vb[b[j]].pop_back();
      output();
    }
    pre[sa[i] - sb[it]] = make_pair(i, it);
  }
  puts("-1");
  return 0;
}
