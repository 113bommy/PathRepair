#include <bits/stdc++.h>
using namespace std;
inline long long readLL() {
  long long a;
  scanf("%lld", &a);
  return a;
}
static const int maxn = 2e5 + 5;
long long n, arr[maxn];
map<long long, pair<long long, long long> > mapper;
int main() {
  n = readLL();
  for (long long ii = 1; ii <= n; ii++) {
    long long k = readLL();
    long long sum = 0;
    for (long long i = 1; i <= k; i++) {
      arr[i] = readLL();
      sum += arr[i];
    }
    for (long long i = 1; i <= k; i++) {
      long long s = sum - arr[i];
      if (mapper.find(s) != mapper.end()) {
        puts("YES");
        printf("%lld %lld\n", mapper[s].first, mapper[s].second);
        printf("%lld %lld\n", ii, i);
        return 0;
      }
    }
    for (long long i = 1; i <= k; i++) {
      long long s = sum - arr[i];
      mapper[s] = make_pair(ii, i);
    }
  }
  puts("NO");
}
