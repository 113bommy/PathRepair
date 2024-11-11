#include <bits/stdc++.h>
using namespace std;
long long n, k;
vector<pair<pair<long long, long long>, long long> > vt;
bool cmp(pair<pair<long long, long long>, long long> x,
         pair<pair<long long, long long>, long long> y) {
  if (x.first.first / k != y.first.first / k)
    return x.first.first / k < y.first.first / k;
  return x.first.second < y.first.second;
}
int main() {
  scanf("%lld", &n);
  for (long long i = 1; i <= n; i++) {
    long long a, b;
    scanf("%lld%lld", &a, &b);
    vt.push_back(pair<pair<long long, long long>, long long>(
        pair<long long, long long>(a, b), i));
  }
  k = 900;
  sort(vt.begin(), vt.end(), cmp);
  for (long long i = 0; i < n; i++) printf("%lld ", vt[i].second);
}
