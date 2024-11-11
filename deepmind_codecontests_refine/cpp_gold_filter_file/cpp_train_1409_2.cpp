#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
map<pair<int, int>, int> p;
map<int, int> x;
map<int, int> y;
int main() {
  long long sum = 0;
  int a, b;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a, &b);
    sum += (long long)x[a]++;
    sum += (long long)y[b]++;
    p[make_pair(a, b)]++;
  }
  for (auto e : p) {
    sum -= ((long long)e.second * (e.second - 1ll)) / 2ll;
  }
  printf("%I64d\n", sum);
  return 0;
}
