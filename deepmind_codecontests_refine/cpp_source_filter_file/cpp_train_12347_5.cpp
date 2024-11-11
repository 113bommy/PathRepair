#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int> > V;
map<int, int> M[4];
long long n, m, s, ans;
void oper(int x, int k) {
  for (int i = 2, ed = sqrt(x + 0.5); i <= ed && x > 1; i++) {
    while (x % i == 0) {
      x /= i;
      M[k][i]++;
    }
  }
  if (x > 1) M[k][x]++;
}
void dfs1(int pos, int need, int k, long long val, const long long& x) {
  if (!need || val >= x) {
    ans += k * x / val;
    return;
  }
  for (int i = pos; i < V.size(); i++) {
    if (val * V[i].first / V[i].first == val)
      dfs1(i + 1, need - 1, k, val * V[i].first, x);
  }
}
void dfs2(int pos, long long val, const long long& mx) {
  if (val <= mx) {
    ans++;
  } else {
    return;
  }
  for (int i = pos; i < V.size(); i++) {
    long long t = val;
    for (int j = 1; j <= V[i].second; j++) {
      t *= V[i].first;
      dfs2(i + 1, t, mx);
    }
  }
}
long long qpow(long long x, int y) {
  long long res = 1;
  while (y) {
    if (y & 1) res *= x;
    y >>= 1;
    x *= x;
  }
  return res;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    V.clear();
    for (int i = 0; i < 3; i++) M[i].clear();
    n = 1, m = 1, s = 2;
    M[2][2]++;
    for (int i = 0, x; i < 3; i++) {
      scanf("%d", &x);
      n *= x;
      oper(x, 0);
    }
    for (int i = 1, x; i <= 3; i++) {
      scanf("%d", &x);
      m *= x;
      oper(x, 1);
    }
    for (int i = 1, x; i <= 3; i++) {
      scanf("%d", &x);
      s *= x;
      oper(x, 2);
    }
    M[3].clear();
    V.clear();
    for (auto it = M[0].begin(); it != M[0].end(); it++) {
      if (it->second > M[2][it->first]) {
        V.emplace_back(
            pair<long long, int>(qpow(it->first, M[2][it->first] + 1), 0));
      }
    }
    ans = m;
    for (int i = 1; i <= V.size(); i++) {
      dfs1(0, i, (i & 1) ? -1 : 1, 1, m);
    }
    V.clear();
    for (auto it = M[2].begin(); it != M[2].end(); it++) {
      if (it->second) {
        V.emplace_back(*it);
      }
    }
    dfs2(0, 1, n);
    printf("%I64d\n", ans);
  }
  return 0;
}
