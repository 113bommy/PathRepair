#include <bits/stdc++.h>
using namespace std;
long long q;
long long B = 28;
long long cur = 0;
long long nxt[2000002][2];
long long sz[2000002];
bool vis[2000002];
vector<long long> GET(long long x) {
  vector<long long> ret;
  for (long long i = 0; i <= B; i++) {
    ret.push_back(x % 2);
    x = x / 2;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}
void inss(long long x) {
  vector<long long> num = GET(x);
  long long v = 0;
  for (long long i = 0; i < num.size(); i++) {
    long long c = num[i];
    if (!vis[nxt[v][c]]) {
      nxt[v][c] = ++cur;
      vis[nxt[v][c]] = true;
    }
    sz[v]++;
    v = nxt[v][c];
  }
  sz[v]++;
}
void dell(long long x) {
  vector<long long> num = GET(x);
  long long v = 0;
  for (long long i = 0; i < num.size(); i++) {
    long long c = num[i];
    sz[v]--;
    v = nxt[v][c];
  }
  sz[v]--;
}
long long qry(long long p, long long l) {
  vector<long long> P = GET(p);
  vector<long long> L = GET(l);
  long long ret = 0;
  long long v = 0;
  for (long long i = 0; i < P.size(); i++) {
    long long same = P[i];
    long long antii = 1 - P[i];
    long long targ = L[i];
    if (targ == 1) {
      if (vis[nxt[v][same]]) {
        ret += sz[nxt[v][same]];
      }
      if (vis[nxt[v][antii]]) {
        v = nxt[v][antii];
      } else {
        return ret;
      }
    } else {
      if (vis[nxt[v][same]]) {
        v = nxt[v][same];
      } else {
        return ret;
      }
    }
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> q;
  long long t, p, l;
  for (long long i = 1; i <= q; i++) {
    cin >> t >> p;
    if (t == 1) {
      inss(p);
    } else if (t == 2) {
      dell(p);
    } else {
      cin >> l;
      long long ans = qry(p, l);
      cout << ans << "\n";
    }
  }
  return 0;
}
