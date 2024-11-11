#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<long long, long long> > a, q;
long long pos[1000005], k[500005];
long long bit[500005];
long long at[500005];
long long ans[500005];
long long n, m;
void update(long long poss) {
  while (poss <= 1000000) {
    bit[poss]++;
    poss += poss & -poss;
  }
}
long long get(long long cnt) {
  long long ok = log2(n) + 2;
  ok = (1 << ok);
  long long now = 0;
  while (ok) {
    if (bit[now + ok] < cnt) {
      cnt -= bit[now + ok];
      now += ok;
    }
    ok /= 2;
  }
  return now + 1;
}
signed main() {
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> at[i];
    a.push({at[i], -i});
  }
  cin >> m;
  for (long long i = 1; i <= m; i++) {
    cin >> k[i] >> pos[i];
    q.push({-k[i], i});
  }
  while (q.size()) {
    pair<long long, long long> hix = q.top();
    q.pop();
    hix.first = -hix.first;
    while (n - (long long)a.size() < hix.first) {
      pair<long long, long long> cac = a.top();
      update(-cac.second);
      a.pop();
    }
    ans[hix.second] = at[get(pos[hix.second])];
  }
  for (long long i = 1; i <= m; i++) {
    cout << ans[i] << '\n';
  }
}
