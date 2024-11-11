#include <bits/stdc++.h>
using namespace std;
int n, ar[2002][6];
vector<int> v;
long long Dis(int i, int j) {
  long long ds = 0;
  for (int k = 1; k <= 5; k++) {
    ds += (ar[i][k] - ar[j][k]) * (ar[i][k] - ar[j][k]);
  }
  return ds;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 5; j++) {
      scanf("%d", &ar[i][j]);
    }
  }
  if (n >= 111) {
    printf("0\n");
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    bool bad = false;
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      for (int k = 1; k <= n; k++) {
        if (i == k || j == k) continue;
        long long ab = Dis(i, j);
        long long ac = Dis(i, k);
        long long bc = Dis(j, k);
        if (bc < (ab + ac)) {
          bad = true;
          break;
        }
      }
      if (bad) break;
    }
    if (!bad) {
      v.push_back(i);
    }
  }
  printf("%d\n", v.size());
  for (auto x : v) {
    printf("%d\n", x);
  }
  return 0;
}
