#include <bits/stdc++.h>
using namespace std;
vector<long long> vec;
int main() {
  long long n, k;
  int m;
  scanf("%lld %d %lld", &n, &m, &k);
  for (int i = 0; i < m; ++i) {
    long long x;
    scanf("%lld", &x);
    vec.push_back(x - 1);
  }
  reverse(vec.begin(), vec.end());
  int cnt = 0, dis = 0;
  while (!vec.empty()) {
    cnt++;
    long long now = (vec.back() - dis) / k;
    int ndis = 0;
    while (!vec.empty() && (vec.back() - dis) / k == now) {
      vec.pop_back();
      ndis++;
    }
    dis += ndis;
  }
  printf("%d", cnt);
  return 0;
}
