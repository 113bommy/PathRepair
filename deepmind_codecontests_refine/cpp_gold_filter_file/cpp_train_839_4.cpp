#include <bits/stdc++.h>
using namespace std;
template <class X, class Y>
void amax(X& x, const Y& y) {
  if (x < y) x = y;
}
template <class X, class Y>
void amin(X& x, const Y& y) {
  if (x > y) x = y;
}
const int INF = 1e9 + 10;
const long long INFL = (long long)1e18 + 10;
const int MAX = 2e5 + 10;
int n;
long long l[MAX], r[MAX];
map<long long, long long> cnt, inc, ddec;
void process() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];
  long long maxr = 0, minl = INFL;
  for (int i = 1; i <= n; i++) {
    inc[l[i]] = ddec[l[i]] = 0;
    inc[r[i]] = ddec[r[i]] = 0;
    amax(maxr, r[i]);
    amin(minl, l[i]);
  }
  ddec[maxr + 1] = 0;
  for (int i = 1; i <= n; i++) {
    inc[l[i]]++;
    auto p2 = ddec.find(r[i]);
    p2 = next(p2);
    p2->second++;
  }
  long long ppost = minl - 1;
  int psum = 0;
  for (auto p : inc) {
    psum -= ddec[p.first];
    cnt[psum] += p.first - ppost - 1;
    psum += p.second;
    cnt[psum]++;
    ppost = p.first;
  }
  for (int i = 1; i <= n; i++) cout << cnt[i] << " ";
}
int main() {
  ios_base::sync_with_stdio(false);
  process();
}
