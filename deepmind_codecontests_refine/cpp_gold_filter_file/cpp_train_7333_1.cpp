#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 1e5;
vector<long long> ans, dv;
long long x, k;
void solve(long long num, long long op) {
  if (num == 1 || op == k) {
    ans.push_back(num);
    return;
  }
  for (long long i = 0; i < dv.size() && dv[i] <= num && ans.size() < MAX_N;
       i++) {
    if (num % dv[i] == 0) solve(dv[i], op + 1);
  }
}
int main() {
  cin >> x >> k;
  for (long long i = 1; i * i <= x; i++) {
    if (x % i != 0) continue;
    dv.push_back(i);
    if (x / i != i) dv.push_back(x / i);
  }
  sort(dv.begin(), dv.end());
  solve(x, 0);
  for (long long i = 0; i < ans.size(); i++) {
    if (i != 0) printf(" ");
    printf("%lld", ans[i]);
  }
  printf("\n");
  return 0;
}
