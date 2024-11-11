#include <bits/stdc++.h>
using namespace std;
long long inf = 1234567890000000LL;
vector<long long> vec;
long long func(long long c) {
  if (c == 0) return inf;
  long long sum = 0;
  bool flag = false;
  for (long long j = 0; j < vec.size(); j++) {
    if (vec[j] / c < vec[j] % c) return inf;
    sum += vec[j] / c;
    if (vec[j] / c - vec[j] % c >= c - 1)
      sum -= (vec[j] / c - vec[j] % c) / (c + 1);
  }
  return sum;
}
int main() {
  long long n;
  scanf("%lld", &n);
  long long num = inf, ans = 0;
  for (long long i = 0; i < n; i++) {
    long long a;
    scanf("%lld", &a);
    vec.push_back(a);
    num = min(num, a);
    ans += a / 2 + a % 2;
  }
  for (long long i = 1; i * i <= num; i++) {
    ans = min(ans, func(num / i - 1));
    ans = min(ans, func(num / i));
  }
  printf("%lld", ans);
}
