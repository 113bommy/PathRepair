#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
using pii = pair<int, int>;
using vi = vector<int>;
mt19937 mrand(time(0));
ll get(ll r) { return ((ll)mrand() * mrand() % r + r) % r; }
ll get(ll l, ll r) { return get(r - l + 1) + l; }
signed main() {
  int _, n;
  for (scanf("%d", &_); _; _--) {
    scanf("%d", &n);
    priority_queue<int> q;
    for (int i = 1, a; i <= n; i++) scanf("%d", &a), q.push(a);
    while (1) {
      if (q.size() == 0) {
        puts("HL");
        break;
      }
      if (q.size() == 1) {
        puts("T");
        break;
      }
      int x = q.top();
      q.pop();
      int y = q.top();
      q.pop();
      x--, y--, x > 0 ? q.push(x) : void(), y > 0 ? q.push(y) : void();
    }
  }
  fprintf(stderr, "time=%.4f\n", (db)clock() / CLOCKS_PER_SEC);
  return 0;
}
