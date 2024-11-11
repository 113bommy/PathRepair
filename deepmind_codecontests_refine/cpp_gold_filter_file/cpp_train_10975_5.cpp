#include <bits/stdc++.h>
using namespace std;
const int nmax = 1e6 + 5;
const int inf = 1 << 30;
int n;
char moves[nmax + 1];
int s[nmax + 1], szstk[nmax + 1];
pair<int, int> mnpart[nmax + 1];
pair<int, int> stk[nmax + 1];
pair<int, int> mnintv[nmax + 1];
int solve() {
  if (moves[n] == 'R') return 0;
  for (int i = 1; i <= n; ++i) {
    s[i] = s[i - 1] + (moves[i] == 'R' ? 1 : -1);
  }
  int top = 0;
  for (int i = n; i > 0; --i) {
    pair<int, int> aux = {s[i], i};
    while (top > 0 && stk[top].first <= s[i]) {
      aux = min(aux, mnintv[top]);
      --top;
    }
    szstk[i] = top + 1;
    mnpart[i] = aux;
    if (top > 0) mnpart[i] = min(mnpart[i], mnpart[stk[top].second]);
    --mnpart[i].first;
    stk[++top] = {s[i], i};
    mnintv[top] = aux;
  }
  int cnt = 0;
  int mx = 0;
  pair<int, int> mn = {0, 0};
  for (int i = 1; i <= n; ++i) {
    mn = min(mn, {s[i], i});
    if (mx >= s[i]) continue;
    mx = s[i];
    pair<int, int> mn_total = min(mn, mnpart[i]);
    if (mn_total.second == n) ++cnt;
  }
  return cnt;
}
int main() {
  fscanf(stdin, "%s", moves + 1);
  n = strlen(moves + 1);
  int mn = 0, mx = 0;
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    sum += (moves[i] == 'R' ? 1 : -1);
    if (i < n) {
      mn = min(mn, sum);
      mx = max(mx, sum);
    }
  }
  if (!(mn <= sum && sum <= mx)) {
    cout << "1\n";
    exit(0);
  }
  int ans = solve();
  for (int i = 1; i <= n; ++i) moves[i] = 'L' + 'R' - moves[i];
  ans += solve();
  cout << ans << "\n";
  return 0;
}
