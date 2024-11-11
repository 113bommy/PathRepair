#include <bits/stdc++.h>
using namespace std;
long long mul(long long a, long long b) {
  return ((a % 998244353) * (b % 998244353)) % 998244353;
}
long long add(long long a, long long b) {
  return ((a % 998244353) + (b % 998244353)) % 998244353;
}
int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n)))
    cin >> a[i];
  long long temp = a[0];
  long long l = 0, mal = 0;
  vector<long long> lel(n);
  map<long long, long long> lc;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    l = 0;
    temp = a[i];
    while (temp) {
      l++;
      temp /= 10;
    }
    lc[l]++;
    mal = max(mal, l);
    lel[i] = l;
  }
  vector<long long> p(2 * mal);
  p[0] = 1;
  for (__typeof(p.size()) i = (1) - ((1) > (p.size()));
       i != (p.size()) - ((1) > (p.size())); i += 1 - 2 * ((1) > (p.size())))
    p[i] = mul(p[i - 1], 10);
  long long ans = 0;
  for (__typeof(n) i = (0) - ((0) > (n)); i != (n) - ((0) > (n));
       i += 1 - 2 * ((0) > (n))) {
    temp = a[i];
    vector<long long> k(lel[i]);
    k[0] = a[i];
    for (__typeof(lel[i]) j = (1) - ((1) > (lel[i]));
         j != (lel[i]) - ((1) > (lel[i])); j += 1 - 2 * ((1) > (lel[i]))) {
      k[j] = 0;
      temp = a[i];
      l = 0;
      while (temp) {
        l++;
        if (l <= (j + 1))
          k[j] = add(k[j], mul(temp % 10, p[(2 * (l - 1))]));
        else
          k[j] = add(k[j], mul(temp % 10, p[(l + j - 1)]));
        temp /= 10;
      }
    }
    for (__typeof(12) o = (1) - ((1) > (12)); o != (12) - ((1) > (12));
         o += 1 - 2 * ((1) > (12))) {
      if (o >= lel[i])
        ans = add(ans, add(mul(k[lel[i] - 1], lc[o]),
                           mul(lc[o], mul(10, k[lel[i] - 1]))));
      else
        ans = add(ans, add(mul(k[o], lc[o]), mul(lc[o], mul(10, k[o - 1]))));
    }
  }
  cout << ans << "\n";
}
