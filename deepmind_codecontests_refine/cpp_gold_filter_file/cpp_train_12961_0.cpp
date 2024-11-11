#include <bits/stdc++.h>
using namespace std;
vector<long long> ans;
long long gcd(long long x, long long y) {
  while (true) {
    if (x == y) return x;
    if (x < y) {
      long long p = (y - 1) / x;
      ans.push_back(-p);
      y -= x * p;
    } else {
      long long p = (x - 1) / y;
      ans.push_back(p);
      x -= y * p;
    }
  }
  throw;
}
int main() {
  long long x, y;
  cin >> x >> y;
  if (gcd(x, y) != 1) {
    printf("Impossible\n");
    return 0;
  }
  for (int i = 0; i < (int)ans.size(); i++)
    printf("%lld%c", abs(ans[i]), (ans[i] > 0 ? 'A' : 'B'));
  printf("\n");
  return 0;
}
