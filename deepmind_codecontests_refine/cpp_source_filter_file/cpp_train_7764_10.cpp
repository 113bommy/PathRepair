#include <bits/stdc++.h>
using namespace std;
const int maxn = 0;
long long n, q, node;
string z;
map<long long, long long> par;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cin >> n >> q;
  int height = 0;
  for (int i = 0; i < 63; i++) {
    if ((1LL << i) <= n) height = i;
  }
  while (q--) {
    cin >> node >> z;
    long long now = n / 2 + 1, depth = 0, last;
    par.clear();
    while (node != now) {
      last = now;
      if (node > now)
        now += (1LL << (height - depth - 1));
      else
        now -= (1LL << (height - depth - 1));
      par[now] = last;
      depth++;
    }
    for (int i = 0; i < z.size(); i++) {
      if (z[i] == 'L') {
        if (now & 1) continue;
        last = now;
        now -= (1 << (height - depth - 1));
        par[now] = last;
        depth++;
      } else if (z[i] == 'R') {
        if (now & 1) continue;
        last = now;
        now += (1 << (height - depth - 1));
        par[now] = last;
        depth++;
      } else {
        if (par[now] == 0) continue;
        now = par[now];
        depth--;
      }
    }
    cout << now << '\n';
  }
}
