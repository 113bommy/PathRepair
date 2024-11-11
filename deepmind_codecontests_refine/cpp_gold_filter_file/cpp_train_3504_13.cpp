#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 9;
const int Maxmask = 1953124 + 10;
const int Mod = 1000000007;
multiset<long long> Q;
vector<long long> ans;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long t;
    scanf("%I64d", &t);
    Q.insert(t);
  }
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    long long target;
    bool find = 0;
    for (int j = 0; j <= 60; j++) {
      if (sum & (1ll << j)) continue;
      target = 1ll << j;
      auto it = Q.lower_bound(target);
      if (it == Q.end()) continue;
      long long val = *it;
      if (val >= target && val < target * 2) {
        sum ^= val;
        ans.push_back(val);
        Q.erase(it);
        find = 1;
        break;
      }
    }
    if (!find) {
      printf("No\n");
      return 0;
    }
  }
  printf("Yes\n");
  for (auto i : ans) printf("%I64d ", i);
}
