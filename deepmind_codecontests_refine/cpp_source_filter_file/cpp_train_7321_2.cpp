#include <bits/stdc++.h>
using namespace std;
vector<int> e[100000];
int c[100000], s[100000], r[100000];
int locate(const vector<int>& u, int x) {
  return lower_bound(u.begin(), u.end(), x,
                     [](int i, int x) { return s[i] < x; }) -
         u.begin();
}
bool gao(int x) {
  for (auto y : e[x])
    if (r[y] != x + 1)
      if (!r[y] || gao(r[y] - 1)) return ~(r[y] = x + 1);
  return false;
}
int main() {
  int n, m;
  scanf("%d", &n);
  vector<int> C, S;
  for (int i = 0; i < n; i++) {
    scanf("%d%d", c + i, s + i);
    C.push_back(i);
    S.push_back(i);
  }
  sort(C.begin(), C.end(), [](int x, int y) { return c[x] > c[y]; });
  sort(S.begin(), S.end(), [](int x, int y) { return s[x] < s[y]; });
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    int d, l;
    scanf("%d%d", &d, &l);
    int x = locate(S, l + 0);
    int y = locate(S, l + 1);
    if (x < n && s[S[x]] == l + 0 && c[S[x]] <= d) e[S[x]].push_back(i);
    if (y < n && s[S[x]] == l + 1 && c[S[y]] <= d) e[S[y]].push_back(i);
  }
  long long ans = 0, cnt = 0;
  for (int i = 0; i < n; i++)
    if (gao(C[i])) ans += c[C[i]];
  for (int i = 0; i < m; i++)
    if (r[i]) cnt++;
  printf("%I64d\n%I64d\n", ans, cnt);
  for (int i = 0; i < m; i++)
    if (r[i]) printf("%d %d\n", i + 1, r[i]);
}
