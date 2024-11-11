#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math,O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
const long long N = 3e5 + 5, oo = 1e18;
long long n, block_size, ans[N], a[N], b[N], type[N], time_end[N], n1, n2,
    process[N], n3, del[N];
pair<long long, long long> lines[N];
struct Line {
  long long a, b;
  Line() {}
  Line(long long _a, long long _b) : a(_a), b(_b) {}
  long long val(long long x) { return a * x + b; }
} st[N];
long long bad(Line a, Line b, Line c) {
  return (c.b - a.b) * (b.a - c.a) <= (c.b - b.b) * (a.a - c.a);
}
void addLine(Line a) {
  if (n3 && st[n3 - 1].a == a.a && st[n3 - 1].b == a.b) n3--;
  while (n3 >= 2 && bad(a, st[n3 - 1], st[n3 - 2])) n3--;
  st[n3++] = a;
}
long long query(long long x) {
  long long ans = -oo, l = 0, r = n3 - 1;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    ans = max(ans, st[mid].val(x));
    long long lmid = (mid == 0 ? -oo : st[mid - 1].val(x)),
              rmid = (mid == n3 - 1 ? -oo : st[mid + 1].val(x));
    if (lmid > rmid)
      r = mid - 1;
    else if (rmid > lmid)
      l = mid + 1;
    else
      break;
  }
  return ans;
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  clock_t T = clock();
  cin >> n;
  for (long long i = 1; i <= n; ++i) {
    cin >> type[i] >> a[i];
    if (type[i] == 1) cin >> b[i];
  }
  block_size = 3000;
  vector<long long> willadd, cur;
  cur.clear();
  for (long long L = 1; L <= n; L += block_size) {
    willadd.clear();
    n3 = 0;
    long long R = min(n, L + block_size - 1);
    for (long long i = L; i <= R; ++i)
      if (type[i] == 2 && a[i] < L) willadd.push_back(a[i]), del[a[i]] = 2;
    vector<pair<long long, long long> > V;
    V.clear();
    for (long long r : cur)
      if (del[r] == 0) V.push_back({a[r], b[r]});
    sort(V.begin(), V.end());
    for (pair<long long, long long> d : V) addLine(Line(d.first, d.second));
    for (long long j = L; j <= R; ++j) {
      if (type[j] == 1) willadd.push_back(j);
      if (type[j] == 2) del[a[j]] = 1;
      if (type[j] == 3) {
        ans[j] = -oo;
        for (long long r : willadd)
          if (del[r] != 1) ans[j] = max(ans[j], a[r] * a[j] + b[r]);
        ans[j] = max(ans[j], query(a[j]));
      }
    }
    for (long long r : willadd)
      if (del[r] == 0) cur.push_back(r);
  }
  for (long long i = 1; i <= n; ++i)
    if (type[i] == 3) {
      if (ans[i] == -oo)
        cout << "EMPTY SET" << '\n';
      else
        cout << ans[i] << '\n';
    }
  return 0;
}
