#include <bits/stdc++.h>
using namespace std;
void file() {}
int tc;
const int N = 2e5 + 5, M = 2e6 + 5, MOD = 1e9 + 7, OO = 1e9;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  file();
  int n, d;
  scanf("%d %d", &n, &d);
  std::vector<int> a(n);
  for (auto &x : a) scanf("%d", &x);
  long long ans = 0;
  for (int i = 0; i < n - 2; i++) {
    auto it = upper_bound((a).begin(), (a).end(), a[i] + d);
    it--;
    int j = it - a.begin();
    long long wa = j - i - 1;
    ans += wa * (wa + 1) / 2;
  }
  printf("%lld\n", ans);
}
