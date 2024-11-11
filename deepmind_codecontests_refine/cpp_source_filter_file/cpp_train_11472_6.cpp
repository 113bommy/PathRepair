#include <bits/stdc++.h>
using namespace std;
vector<long long> gen() {
  vector<long long> ret({4, 7});
  for (int i = 0; i < (int)ret.size(); i++) {
    if (ret[i] > 2e17) break;
    ret.push_back(ret[i] * 10 + 4);
    ret.push_back(ret[i] * 10 + 7);
  }
  cerr << ret.size() << " " << ret.back() << '\n';
  return ret;
}
const int N = 1e5 + 15;
long long l[N], r[N];
inline long long func(vector<long long> &lucky, int n, int mi,
                      long long width) {
  if (mi == 0) return 0;
  int sz = lucky.size();
  long long ret = 4e18;
  __int128 suml = 0, sumr = 0;
  for (int i = 0; i < n; i++) {
    suml += l[i];
  }
  int pl = 0, pr = 0;
  for (int i = 0, j = mi - 1; j < sz; i++, j++) {
    if (lucky[j] - lucky[i] + 1 > width) continue;
    while (pl < n && l[pl] <= lucky[i]) {
      suml -= l[pl];
      pl++;
    }
    while (pr < n && r[pr] <= lucky[j]) {
      sumr += r[pr];
      pr++;
    }
    __int128 tmp = suml - sumr;
    tmp += __int128(lucky[i]) * (n - pl);
    tmp += __int128(lucky[j]) * pr;
    if (tmp < ret) ret = tmp;
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  vector<long long> lucky = gen();
  int sz = lucky.size();
  int n;
  long long k;
  cin >> n >> k;
  long long width = 4e18;
  for (int i = 0; i < n; i++) {
    cin >> l[i] >> r[i];
    width = min(width, r[i] - l[i] + 1);
  }
  sort(l, l + n);
  sort(r, r + n);
  int lo = 0, hi = sz;
  while (lo < hi) {
    int mi = lo + (hi - lo + 1) / 2;
    if (func(lucky, n, mi, width) <= k)
      lo = mi;
    else
      hi = mi - 1;
  }
  cout << lo << '\n';
  return 0;
}
