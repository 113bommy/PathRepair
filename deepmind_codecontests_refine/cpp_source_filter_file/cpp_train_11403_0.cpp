#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e18;
const long long maxn = 8e5 + 10;
const long long mod = 1e9 + 7;
long long n, q, k, M;
long long a[maxn];
vector<pair<long long, long long> > Q[maxn];
vector<long long> ve;
long long mp(long long x) {
  return upper_bound(ve.begin(), ve.end(), x) - ve.begin();
}
long long fen[maxn];
void upd(long long pos, long long val) {
  for (; pos <= M; pos = (pos | (pos + 1))) fen[pos] = max(fen[pos], val);
}
long long qu(long long pos) {
  long long MX = 0;
  pos = min(pos, M);
  for (; pos >= 0; pos = (pos & (pos + 1)) - 1) MX = max(fen[pos], MX);
  return MX;
}
long long L[maxn], R[maxn];
long long le[maxn], ri[maxn];
long long fel[maxn], num[maxn];
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    ve.push_back(a[i]);
  }
  for (long long i = 1; i <= q; i++) {
    long long a, b;
    cin >> a >> b;
    fel[i] = a;
    Q[a].push_back({b, i});
    ve.push_back(b);
  }
  sort(ve.begin(), ve.end());
  ve.resize(unique(ve.begin(), ve.end()) - ve.begin());
  M = (long long)ve.size();
  long long lis = 0;
  for (long long i = 1; i <= n; i++) {
    for (auto X : Q[i]) {
      long long id = X.second;
      long long Y = mp(X.first);
      L[id] = qu(Y - 1);
    }
    long long X = mp(a[i]);
    le[i] = qu(X - 1) + 1;
    lis = max(lis, qu(X - 1) + 1);
    upd(X, qu(X - 1) + 1);
  }
  memset(fen, 0, sizeof fen);
  for (long long i = n; i >= 1; i--) {
    for (auto X : Q[i]) {
      long long id = X.second;
      long long Y = mp(X.first);
      R[id] = qu(M - Y);
    }
    long long X = mp(a[i]);
    ri[i] = qu(M - X) + 1;
    upd(M - X + 1, qu(M - X) + 1);
  }
  for (long long i = 1; i <= n; i++)
    if (le[i] + ri[i] - 1 == lis) num[le[i]]++;
  for (long long i = 1; i <= q; i++) {
    if (le[fel[i]] + ri[fel[i]] - 1 == lis) {
      if (num[le[i]] == 1)
        cout << max(L[i] + R[i] + 1, lis - 1) << "\n";
      else
        cout << max(L[i] + R[i] + 1, lis) << "\n";
    } else
      cout << max(L[i] + R[i] + 1, lis) << "\n";
  }
}
