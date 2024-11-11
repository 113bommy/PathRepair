#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 * 1000;
int n, honest = 0;
vector<int> cand[MAXN + 1];
int check(int c) {
  int cnt = honest, res = 0;
  vector<int> r;
  for (int i = 0; i <= MAXN; i++)
    for (int j = 0; j < cand[i].size(); j++)
      if (c + j <= cand[i].size())
        res += cand[i][j], cnt++;
      else
        r.push_back(cand[i][j]);
  sort(r.begin(), r.end());
  if (c < cnt) return 2000 * 1000 * 1000;
  for (int i = 0; i < r.size() && cnt < c; i++) res += r[i], cnt++;
  return res;
}
void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (a == 0)
      honest++;
    else
      cand[a].push_back(b);
  }
  for (int i = 0; i <= MAXN; i++) sort(cand[i].begin(), cand[i].end());
}
int main() {
  init();
  int l = 0, r = n;
  while (r - l > 10) {
    int m1 = check((2 * l + r) / 3);
    int m2 = check((l + 2 * r) / 3);
    if (m1 == 2000 * 1000 * 1000)
      l = (2 * l + r) / 3;
    else if (m1 > m2)
      l = (2 * l + r) / 3;
    else
      r = (l + 2 * r) / 3;
  }
  int ans = 2000 * 1000 * 1000;
  for (int i = l; i <= r; i++) ans = min(ans, check(i));
  cout << ans;
  return 0;
}
