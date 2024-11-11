#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int pre[N];
int nxt[N];
int col[N];
int num[N];
priority_queue<pair<int, int> > q, del;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, a, cnt = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (a == col[cnt])
      num[cnt]++;
    else
      col[++cnt] = a, num[cnt] = 1;
  }
  for (int i = 1; i <= cnt; i++)
    pre[i] = i - 1, nxt[i] = i + 1, q.push(make_pair(num[i], -i));
  while (cnt) {
    while (!del.empty() && del.top() == q.top()) del.pop(), q.pop();
    a = -q.top().second;
    q.pop();
    int t = pre[a], _t = nxt[a];
    pre[_t] = t, nxt[t] = _t;
    if (t && col[t] == col[_t]) {
      del.push(make_pair(num[t], -t)), del.push(make_pair(num[_t], -_t));
      num[t] += num[_t], nxt[t] = nxt[_t], pre[nxt[_t]] = t;
      q.push(make_pair(num[t], -t));
      cnt--;
    }
    cnt--;
    ans++;
  }
  cout << ans << endl;
  return 0;
}
