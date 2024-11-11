#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int num[maxn];
long long Query(vector<int> query) {
  if (query.size() == 0) return 0;
  cout << "? " << query.size();
  for (auto x : query) cout << ' ' << x;
  cout << endl;
  long long res;
  cin >> res;
  return res;
}
int main() {
  int n;
  scanf("%d", &n);
  int P = 13, cnt = 0;
  vector<int> ask[20];
  for (int i = 0; i <= (1 << P) - 1; i++) {
    if (__builtin_popcount(i) != P / 2) continue;
    num[++cnt] = i;
    for (int j = 0; j < P; j++)
      if (!((1 << j) & i)) ask[j].push_back(cnt);
    if (cnt == n) break;
  }
  long long w[20], ans[20] = {0};
  for (int i = 0; i < P; i++) w[i] = Query(ask[i]);
  for (int i = 1; i <= cnt; i++)
    for (int j = 0; j < P; j++)
      if ((1 << j) & num[i]) ans[i] |= w[j];
  cout << '!';
  for (int i = 1; i <= n; i++) cout << ' ' << ans[i];
  cout << endl;
  return 0;
}
