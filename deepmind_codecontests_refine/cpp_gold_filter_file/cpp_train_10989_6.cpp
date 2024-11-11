#include <bits/stdc++.h>
using namespace std;
const long long maxn = 1e18 + 10;
vector<long long> sum;
void init() {
  sum.clear();
  sum.push_back(1);
  sum.push_back(2);
  sum.push_back(3);
  while (*sum.rbegin() < maxn) {
    int sz = sum.size();
    long long tmp = sum[sz - 1] + sum[sz - 2];
    sum.push_back(tmp);
  }
}
int main() {
  init();
  long long n;
  scanf("%lld", &n);
  for (int i = 0; true; i++) {
    if (sum[i] > n) {
      printf("%d\n", i - 1);
      break;
    }
  }
  return 0;
}
