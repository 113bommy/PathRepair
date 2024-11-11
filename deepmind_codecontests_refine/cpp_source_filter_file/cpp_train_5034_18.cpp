#include <bits/stdc++.h>
using namespace std;
const long INF = 1000000000;
int main() {
  long n, a;
  vector<long> v, p1, p2, sums;
  long long sum = 0;
  cin >> n;
  v.reserve(n);
  sums.resize(n + 1);
  sums[0] = 0;
  for (long i = 1; i <= n; ++i) {
    cin >> a;
    v.push_back(a);
    sums[i] = sums[i - 1] + a;
    sum += a;
  }
  if (sum % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  long ts = sum / 3;
  for (long i = 1; i < n; ++i) {
    if (sums[i] == ts) p1.push_back(i);
    if ((sums[n] - sums[i]) == ts) p2.push_back(i);
  }
  long ans = 0, it = 0;
  if ((p1.size() == 0) || (p2.size() == 0)) {
    cout << 0 << endl;
    return 0;
  }
  p2.push_back(INF);
  for (long i = 0; i < p1.size(); ++i) {
    if ((n - p1[i]) < 2) break;
    while ((p2[it] <= p1[i]) && (it <= p2.size() - 1)) ++it;
    ans += p2.size() - it - 1;
  }
  cout << ans << endl;
  return 0;
}
