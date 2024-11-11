#include <bits/stdc++.h>
using namespace std;
vector<long long> bitmask[70];
int main() {
  int n;
  long long x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%lld", &x);
    for (int j = 0; j < 65; j++) {
      if ((x >> j) % 2 == 1) {
        bitmask[j].push_back(x);
        break;
      }
    }
  }
  int ma = 0, kuy;
  for (int i = 0; i < 65; i++) {
    if (bitmask[i].size() > ma) {
      ma = bitmask[i].size();
      kuy = i;
    }
  }
  printf("%d\n", n - ma);
  for (int i = 0; i < 65; i++) {
    if (i != kuy) {
      for (auto it : bitmask[i]) {
        printf("%lld\n", it);
      }
    }
  }
}
