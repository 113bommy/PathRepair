#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v, v1;
int main() {
  long long x;
  scanf("%lld", &x);
  long long X = x * 6;
  for (long long i = 1; i <= 1000000; i++) {
    long long tmp = i * (i + 1);
    if (X % tmp != 0) continue;
    long long y = X / tmp;
    y += i;
    y--;
    if (y % 3 != 0) continue;
    y /= 3;
    if (y < i) break;
    v.push_back(make_pair(i, y));
  }
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i].first != v[i].second)
      v1.push_back(make_pair(v[i].second, v[i].first));
  }
  int sz = v.size() + v1.size();
  printf("%d\n", sz);
  for (int i = 0; i < v.size(); i++)
    printf("%lld %lld\n", v[i].first, v[i].second);
  for (int i = 0; i < v1.size(); i++)
    printf("%lld %lld\n", v1[i].first, v1[i].second);
  return 0;
}
