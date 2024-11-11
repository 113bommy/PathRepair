#include <bits/stdc++.h>
using namespace std;
int a[200050], b[200050];
map<int, int> M, have;
vector<int> ans;
int gd;
void change(int num, char oper) {
  if (M[num] > 0) {
    if (have[num] == M[num]) gd--;
    if (oper)
      have[num]++;
    else
      have[num]--;
    if (have[num] == M[num]) gd++;
  }
  return;
}
void solution() {
  int n, m, p, req = 0;
  cin >> n >> m >> p;
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (m); i++) {
    scanf("%d", &b[i]);
    if (M[b[i]] == 0) req++;
    M[b[i]]++;
  }
  for (int i = (1); i <= (p); i++) {
    if (1LL * (m - 1) * p + i > n) break;
    have.clear();
    gd = 0;
    for (int j = (0); j <= (m - 1); j++) change(a[j * p + i], 1);
    if (gd == req) ans.push_back(i);
    int k = i;
    while (k + m * p <= n) {
      change(a[k], 0);
      change(a[k + m * p], 1);
      if (gd == req) ans.push_back(k + p);
      k += p;
    }
  }
  sort(ans.begin(), ans.end());
  if (ans.size() > 0) {
    cout << ans.size() << '\n' << ans[0];
    for (int i = (1); i <= (ans.size() - 1); i++) printf(" %d", ans[i]);
  } else
    cout << 0;
  cout << '\n';
}
int main() { solution(); }
