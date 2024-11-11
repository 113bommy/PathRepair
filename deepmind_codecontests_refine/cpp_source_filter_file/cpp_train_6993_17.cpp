#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 211111;
long long n, a[MAXN], q, cnt[MAXN], L[MAXN], R[MAXN], htl, htr, most, ret;
vector<long long> E;
vector<pair<pair<long long, long long>, long long> > k;
int main() {
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
    if (!cnt[a[i]]) {
      E.push_back(a[i]);
      L[a[i]] = i;
    }
    cnt[a[i]]++;
    R[a[i]] = max(R[a[i]], i);
  }
  for (auto u : E) {
    k.push_back(pair<pair<long long, long long>, long long>(
        pair<long long, long long>(L[u], R[u]), u));
  }
  sort(k.begin(), k.end());
  for (long long i = 0; i <= (long long)k.size() - 1; i++) {
    long long u = k[i].second;
    long long l = k[i].first.first;
    long long r = k[i].first.second;
    if (l > htr) {
      if (htr) ret = ret + (htr - htl + 1) - most;
      htl = l;
      htr = r;
      most = cnt[u];
    } else {
      htr = max(htr, r);
      most = max(most, cnt[u]);
    }
  }
  ret = ret = (htr - htl + 1) - most;
  cout << ret;
}
