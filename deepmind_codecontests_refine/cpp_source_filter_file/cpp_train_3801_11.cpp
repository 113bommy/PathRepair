#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  long long x;
  scanf("%lld", &x);
  vector<pair<long long, long long> > ans;
  int f = 0;
  for (long long n = 1; n <= 1000010; n++) {
    long long k = x - n * n - n + ((n * (n + 1) * (n + 5)) / 6);
    long long t = n * (n + 1);
    t /= 2;
    if (k % t == 0) {
      if (k / t >= n) ans.push_back(pair<long long, long long>(n, k / t));
      if (n == k / t) f = 1;
    }
  }
  printf("%d\n", 2 * (int)ans.size() - f);
  for (int i = 0; i < ans.size(); i++) {
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  }
  for (int i = ans.size() - f - 1; i >= 0; i--) {
    printf("%lld %lld\n", ans[i].second, ans[i].first);
  }
  return 0;
}
