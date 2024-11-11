#include <bits/stdc++.h>
using namespace std;
set<long long> good;
long long thr[11];
void fill(long long i, long long s) {
  if (i == 11) {
    good.insert(s);
    return;
  }
  fill(i + 1, s);
  fill(i + 1, s + thr[i]);
}
void pre() {
  thr[0] = 1;
  for (long long i = 1; i < 10; i++) thr[i] = 3 * thr[i - 1];
  fill(0, 0);
  good.erase(good.begin());
}
void mymain() {
  long long n;
  cin >> n;
  cout << *good.upper_bound(n) << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  long long t = 1;
  cin >> t;
  pre();
  for (long long tt = 0; tt < t; tt++) {
    mymain();
  }
  return 0;
}
