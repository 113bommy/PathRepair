#include <bits/stdc++.h>
using namespace std;
int fen[200005];
int n;
void update(int u, int val) {
  while (u <= n) fen[u] += val, u += u & -u;
}
int sum(int u) {
  int res = 0;
  while (u > 0) res += fen[u], u -= u & -u;
  return res;
}
int main() {
  string s, t;
  cin >> n >> s;
  t = s;
  reverse(t.begin(), t.end());
  for (int i = 1; i <= n; i++) fen[i] = 0;
  deque<int> v[26];
  int i = 0;
  for (auto x : s) v[x - 'a'].push_back(i++);
  int ans = 0;
  for (i = 0; i < n; i++) {
    int c = v[t[i] - 'a'][0];
    int cur = c + sum(c + 1);
    v[t[i] - 'a'].pop_front();
    if (cur == i)
      continue;
    else {
      ans += cur - i;
      update(1, 1);
      update(c + 2, -1);
    }
  }
  cout << ans << endl;
}
