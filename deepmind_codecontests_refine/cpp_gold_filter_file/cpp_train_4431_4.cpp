#include <bits/stdc++.h>
using namespace std;
long long n, k, sum = 0, ans = 0;
vector<long long> c;
vector<bool> id;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  c.resize(n);
  id.resize(n, false);
  for (long long i = 0; i < n; i++) {
    cin >> c[i];
    sum += c[i];
  }
  for (long long i = 0; i < k; i++) {
    long long cap;
    cin >> cap;
    id[cap - 1] = true;
  }
  for (long long i = 0; i < n; i++) {
    if (id[i]) ans += c[i] * (sum - c[i]);
    if (i > 0 && !id[i - 1] && !id[i]) ans += c[i - 1] * c[i];
    if (id[i]) sum -= c[i];
  }
  if (!id[0] && !id[n - 1]) ans += c[0] * c[n - 1];
  cout << ans;
  return 0;
}
