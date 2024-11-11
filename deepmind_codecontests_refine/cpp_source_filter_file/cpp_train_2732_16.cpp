#include <bits/stdc++.h>
using namespace std;
struct node {
  long long p, k, a;
  bool operator<(const node &oth) const {
    if (k == oth.k) return p > oth.p;
    return k < oth.k;
  }
};
bool npr[1005];
long long prm[1005];
void EulerSieve() {
  for (long long i = 2; i <= 1000; i++) {
    if (!npr[i]) prm[++prm[0]] = i;
    for (long long j = 1; j <= prm[0] && i * prm[j] <= 1000; j++) {
      npr[i * prm[j]] = true;
      if (i % prm[j] == 0) break;
    }
  }
}
node tmp[1000];
signed main() {
  long long t;
  cin >> t;
  EulerSieve();
  while (t--) {
    priority_queue<node> pq;
    for (long long i = 1; i <= prm[0]; i++) {
      node cur = (node){prm[i], 1, prm[i]};
      pq.push(cur);
    }
    long long ans = 1;
    for (long long cnt = 1; cnt <= 22; cnt++) {
      long long now = 1, ncnt = 0;
      while (!pq.empty() && 1.0 * now * pq.top().a <= 1e18) {
        tmp[++ncnt] = pq.top();
        now *= tmp[ncnt].a;
        pq.pop();
      }
      cout << "? " << now << endl;
      cout.flush();
      long long res;
      cin >> res;
      for (long long i = 1; i <= ncnt; i++) {
        if (res % tmp[i].a == 0) {
          ans /= tmp[i].k;
          ans *= (++tmp[i].k);
          node cur = (node){tmp[i].p, tmp[i].k + 1, tmp[i].a * tmp[i].p};
          pq.push(cur);
        }
      }
    }
    cout << "! " << ans * 2LL << endl;
    cout.flush();
  }
  return 0;
}
