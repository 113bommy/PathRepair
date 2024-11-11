#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int t[3][N];
inline int lowbit(int x) { return x & (-x); }
inline void add(int id, int k, int x) {
  for (int i = k; i < N; i += lowbit(i)) t[id][i] += x;
}
inline int query(int id, int k) {
  int res = 0;
  for (int i = k; i; i -= lowbit(i)) res += t[id][i];
  return res;
}
int to[300];
int n, q;
int a[N];
char s[N];
set<int> S[3];
inline int solve() {
  int cnt = 0;
  for (int i = 0; i < 3; i++)
    if (!S[i].empty()) cnt++;
  if (cnt == 1) return n;
  if (cnt == 2)
    for (int i = 0; i < 3; i++)
      if (S[i].empty()) return S[(i + 2) % 3].size();
  int ans = 0, L, R;
  for (int i = 0; i < 3; i++) {
    L = *S[(i + 1) % 3].begin(), R = *S[(i + 2) % 3].begin();
    if (R >= L) ans += query(i, R) - query(i, L - 1);
    L = *S[(i + 2) % 3].rbegin(), R = *S[(i + 1) % 3].begin();
    if (R >= L) ans += query(i, R) - query(i, L - 1);
  }
  return n - ans;
}
int main() {
  to['R'] = 0, to['P'] = 1, to['S'] = 2;
  scanf("%d%d", &n, &q);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = to[s[i]];
    add(a[i], i, 1);
    S[a[i]].insert(i);
  }
  printf("%d\n", solve());
  while (q--) {
    int x;
    char ch[5];
    scanf("%d%s", &x, ch + 1);
    add(a[x], x, -1);
    S[a[x]].erase(x);
    a[x] = to[ch[1]];
    add(a[x], x, 1);
    S[a[x]].insert(x);
    printf("%d\n", solve());
  }
  return 0;
}
