#include <bits/stdc++.h>
using namespace std;
const int N = 2e5, M = 500;
int n, a[N], lst[2 * N + 1], f = 0, nxt[N], prv[N], s[N];
vector<int> p[N];
int solve1(int v) {
  int sol = 0;
  for (int i = 0; i <= 2 * n; i++) lst[i] = -1;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == v)
      sum++;
    else if (a[i] == f)
      sum--;
    lst[sum + n] = i;
  }
  for (int i = 2 * n - 1; 0 <= i; i--) lst[i] = max(lst[i], lst[i + 1]);
  sum = 0;
  for (int i = 0; i < n; i++) {
    sol = max(sol, lst[n + sum] - i + 1);
    if (a[i] == v)
      sum++;
    else if (a[i] == f)
      sum--;
  }
  return sol;
}
int solve2(int v) {
  int sol = 0;
  int l = p[v].size();
  for (int i = 0; i <= 2 * l; i++) lst[i] = -1;
  int e = n;
  for (int i : p[v]) {
    int db = s[e - 1] - s[i];
    if (db) {
      for (int j = 0; j + db - 1 <= 2 * l; j++) lst[j] = lst[j + db - 1];
      for (int j = 2 * l - db + 2; j <= 2 * l; j++) lst[j] = -1;
    } else
      for (int j = 2 * l; 1 <= j; j--) lst[j] = lst[j - 1];
    db = 0;
    int act = i;
    while (act < e && db <= l + 1) {
      act = nxt[act];
      lst[l + 1 - db] = max(lst[l + 1 - db], act - 1);
      db++;
    }
    for (int j = 2 * l - 1; 0 <= j; j--) lst[j] = max(lst[j], lst[j + 1]);
    act = i;
    db = 0;
    while (0 <= act && db <= l) {
      act = prv[act];
      sol = max(sol, lst[l + db] - act);
      db++;
    }
    e = i;
  }
  return sol;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = n - 1; 0 <= i; i--) p[--a[i]].push_back(i);
  for (int i = 1; i < n; i++)
    if (p[i].size() > p[f].size()) f = i;
  nxt[n - 1] = n;
  prv[0] = -1;
  s[0] = (a[0] == f ? 1 : 0);
  for (int i = n - 2; 0 <= i; i--)
    nxt[i] = (a[i + 1] == f ? i + 1 : nxt[i + 1]);
  for (int i = 1; i < n; i++) prv[i] = (a[i - 1] == f ? i - 1 : prv[i - 1]);
  for (int i = 1; i < n; i++) s[i] = (a[i] == f ? s[i - 1] + 1 : s[i - 1]);
  int sol = 0;
  for (int v = 0; v < n; v++)
    if (v != f && !p[v].empty())
      sol = max(sol, (p[v].size() >= M ? solve1(v) : solve2(v)));
  cout << sol << "\n";
  return 0;
}
