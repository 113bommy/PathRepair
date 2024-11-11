#include <bits/stdc++.h>
using namespace std;
const int64_t INF = 1e18, MOD = 1e9 + 7;
const int64_t MAXN = 1e3;
pair<int64_t, int64_t> last = {0, 0};
pair<int64_t, int64_t> ask(int64_t i) {
  if (i != -1) cout << "+ " << (i + 1) << endl;
  int64_t a, b;
  cin >> a >> b;
  a -= last.first, b -= last.second;
  last = {a + last.first, b + last.second};
  return {a, b};
}
int64_t search(int64_t v) {
  for (int64_t i = 1; i < MAXN; i++) {
    if ((i * (i - 1)) / 2 == v) return i;
  }
  return -1;
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  int64_t n;
  cin >> n;
  ask(-1);
  vector<int64_t> ans(n);
  pair<int64_t, int64_t> q1 = ask(0);
  pair<int64_t, int64_t> q2 = ask(1);
  pair<int64_t, int64_t> q3 = ask(2);
  pair<int64_t, int64_t> q4 = ask(0);
  ans[0] = search(q4.first) + 1;
  if (q2.second == 0)
    ans[2] = 1;
  else
    ans[2] = search(q3.first) + 1;
  ans[1] = q4.second / ans[2];
  int64_t carry = q3.second - ans[1] * (ans[0] - 1);
  for (int64_t i = 3; i < n - 1; i++) {
    pair<int64_t, int64_t> qur = ask(i);
    if (carry == 0)
      ans[i] = 1;
    else
      ans[i] = search(qur.first);
    carry = qur.second - ans[i - 1] * ans[i - 2];
  }
  if (carry == 0)
    ans[n - 1] = 0;
  else
    ans[n - 1] = carry / ans[n - 3];
  ans[0]--;
  for (int64_t i = 0; i < n - 1; i++) ans[i]--;
  cout << "! ";
  for (int64_t i = 0; i < n; i++) cout << ans[i] << " ";
  cout << endl;
  return 0;
}
