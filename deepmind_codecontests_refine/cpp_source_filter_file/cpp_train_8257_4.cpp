#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:66777216")
using namespace std;
int a, b, c, d, i, j, n, m, k;
set<pair<int, int> > q;
long long mas[102];
int main() {
  cin >> n;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    cin >> a >> b;
    q.insert(make_pair(b, a));
  }
  cin >> m;
  for (int _n((m)-1), i(0); i <= _n; i++) {
    cin >> mas[i];
  }
  mas[m] = 1000000000000000000LL;
  c = 0;
  long long cur = 0, ans = 0;
  while (!q.empty()) {
    pair<int, int> t = *q.begin();
    q.erase(q.begin());
    if (!t.second) continue;
    long long need = mas[c] - cur;
    if (need >= t.second) {
      cur += t.second;
      ans += (long long)t.second * (c + 1) * t.first;
      continue;
    }
    cur += need;
    ans += need * (c + 1) * t.first;
    q.insert(make_pair(t.first, (int)(t.second - need)));
    ++c;
  }
  cout << ans << endl;
}
