#include <bits/stdc++.h>
using namespace std;
bool comp(long long a, long long b) {
  if (a > b) return 1;
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, d, m;
  cin >> n >> d >> m;
  vector<long long> vb, vs;
  vb.reserve(n);
  vs.reserve(n);
  for (long long i = 0; i < n; i++) {
    long long z;
    cin >> z;
    if (z > m)
      vb.push_back(z);
    else
      vs.push_back(z);
  }
  sort(vb.begin(), vb.end(), comp);
  sort(vs.begin(), vs.end(), comp);
  long long n1 = vb.size(), n2 = vs.size();
  long long sumb[n1], sums[n2 + 1];
  long long temp = 0;
  for (long long i = 0; i < n1; i++) {
    temp += vb[i];
    sumb[i] = temp;
  }
  temp = 0;
  sums[0] = 0;
  for (long long i = 1; i <= n2; i++) {
    temp += vs[i - 1];
    sums[i] = temp;
  }
  long long ans = 0;
  if (vb.size() == 0) {
    cout << sums[n2 - 1] << "\n";
    return 0;
  }
  for (long long x1 = 1; x1 <= n1; x1++) {
    if (x1 * d >= (n1 - x1) && (x1 - 1) * d <= (n1 + n2 - x1)) {
      long long te = sumb[x1 - 1] + sums[n2 - max((x1 - 1) * d - n1 + x1, 0LL)];
      ans = max(ans, te);
    }
  }
  cout << ans << "\n";
  return 0;
}
