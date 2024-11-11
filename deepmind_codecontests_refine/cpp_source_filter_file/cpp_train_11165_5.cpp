#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
long long t, n, p, c, ma, vas, cc = 1000000007;
long long astt(long long p, long long s) {
  long long v = 1, c = 1000000;
  if (s == 0) return 1;
  if (s == 1) return p;
  v = astt(p, s / 2);
  if (v >= c) return c;
  v *= v;
  if (v >= c) return c;
  if (s % 2) v *= p;
  if (v >= c) return c;
  return v;
}
long long ast(long long p, long long s) {
  long long v = 1;
  if (s == 0) return 1;
  if (s == 1) return p;
  v = ast(p, s / 2);
  v %= cc;
  v *= v;
  v %= cc;
  if (s % 2) v *= p;
  v %= cc;
  return v;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> t;
  while (t--) {
    vector<long long> v;
    vector<pair<long long, int>> pr;
    cin >> n >> p;
    for (int(i) = (0); ((i)) < ((n)); ((i))++) {
      cin >> c;
      ma = max(ma, c);
      v.emplace_back(c);
    }
    sort(v.begin(), v.end());
    int in = 0, al = 0;
    while (in < n) {
      if (in == n - 1 or v[in + 1] != v[in]) {
        pr.emplace_back(v[in], in - al + 1);
        al = in + 1;
      }
      in++;
    }
    reverse(pr.begin(), pr.end());
    int s = pr.size(), vi = 0;
    in = 0;
    while (in < s) {
      while (in < s and pr[in].second % 2 == 0) in++;
      vi = in;
      if (in < s) {
        pr[in].second = 1;
        long long k = pr[in].first;
        long long va = 1;
        int vi = in;
        in++;
        bool sai = 0;
        while (in < s) {
          va *= astt(p, k - pr[in].first);
          va = max(va, (long long)1000000);
          k = pr[in].first;
          if (pr[in].second < va) {
            va -= pr[in].second;
            in++;
          } else {
            sai = 1;
            pr[in].second -= va;
            break;
          }
        }
        if (sai == 0) break;
      }
    }
    if (vi >= s)
      cout << 0 << endl;
    else {
      long long su = pr[vi].second * ast(p, pr[vi].first);
      su %= cc;
      vi++;
      long long te = 0;
      while (vi < s) {
        te += pr[vi].second * ast(p, pr[vi].first);
        te %= cc;
        vi++;
      }
      cout << ((su + cc - te) % cc) << endl;
    }
  }
}
