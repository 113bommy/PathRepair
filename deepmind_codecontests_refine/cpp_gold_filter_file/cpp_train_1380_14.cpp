#include <bits/stdc++.h>
using namespace std;
unsigned long long query(vector<int>& x) {
  if (x.empty()) {
    return 0;
  } else {
    printf("? %lu", x.size());
    for (int i = 0; i < x.size(); i++) {
      printf(" %d", x[i] + 1);
    }
    printf("\n");
    fflush(stdout);
    unsigned long long ret;
    scanf("%llu", &ret);
    return ret;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> pc6;
  for (int i = 0; i < (1 << 13); i++) {
    if (__builtin_popcount(i) == 6) {
      pc6.push_back(i);
    }
  }
  vector<unsigned long long> rets(13);
  for (int i = 0; i < 13; i++) {
    vector<int> toQuery;
    for (int j = 0; j < n; j++) {
      if (pc6[j] >> i & 1) {
        toQuery.push_back(j);
      }
    }
    rets[i] = query(toQuery);
  }
  printf("!");
  for (int i = 0; i < n; i++) {
    unsigned long long ans(0);
    for (int j = 0; j < 13; j++) {
      if (~pc6[i] >> j & 1) {
        ans |= rets[j];
      }
    }
    printf(" %llu", ans);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
