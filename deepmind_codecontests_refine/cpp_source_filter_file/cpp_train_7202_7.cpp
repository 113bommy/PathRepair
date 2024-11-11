#include <bits/stdc++.h>
using namespace std;
const int oo = (int)1e9;
vector<long long> v;
void gen(long long x) {
  if (x > 1e10) return;
  v.push_back(x);
  gen(x * 10 + 4);
  gen(x * 10 + 7);
}
long long calc(int x) {
  long long res = 0;
  for (int i = 1; i < (int)v.size(); ++i) {
    int mn = min(v[i] - v[i - 1], x - v[i - 1]);
    if (mn < 0) return res;
    res += v[i] * mn;
  }
  return res;
}
int main() {
  gen(0);
  sort(v.begin(), v.end());
  int l, r;
  scanf("%d%d", &l, &r);
  long long res = calc(r);
  res -= calc(l - 1);
  printf("%lld\n", res);
  return 0;
}
