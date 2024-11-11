#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e+9 + 7;
const long long INFLL = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const long long MAXN = 1e+5 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long i, j, n;
  cin >> n;
  vector<long long> inp(n);
  for (auto& a : inp) cin >> a;
  long long sumw = 0, sumb = 0;
  for (i = 0; i < n; ++i)
    sumw += (inp[i] + (inp[i] & 1 == i & 1)) / 2,
        sumb += (inp[i] + (inp[i] & 1 != i & 1)) / 2;
  cout << min(sumw, sumb) << '\n';
  return 0;
}
