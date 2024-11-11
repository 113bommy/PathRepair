#include <bits/stdc++.h>
using namespace std;
long long n, m;
vector<long long> ve;
void dfs(long long num, long long len, long long sum) {
  ve.push_back(num);
  if (len == 18) return;
  dfs(num * 10 + 0, len + 1, sum);
  if (sum < 3) {
    for (long long i = 1; i <= 9; i++) {
      dfs(num * 10 + i, len + 1, sum + 1);
    }
  }
}
signed main() {
  for (long long i = 1; i <= 9; i++) {
    dfs(i, 1, 1);
  }
  sort(ve.begin(), ve.end());
  long long T;
  cin >> T;
  while (T--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    cout << upper_bound(ve.begin(), ve.end(), r) -
                lower_bound(ve.begin(), ve.end(), l)
         << endl;
  }
  return 0;
}
