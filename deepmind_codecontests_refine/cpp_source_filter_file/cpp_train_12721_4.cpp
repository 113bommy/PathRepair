#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
vector<int> ve;
int check(int x) {
  while (x) {
    if (x % 3 >= 2) return 0;
    x /= 3;
  }
  return 1;
}
int main() {
  for (int i = 1;; i++) {
    if (check(i)) {
      ve.push_back(i);
      if (i > 10000) break;
    }
  }
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%d\n", *upper_bound(ve.begin(), ve.end(), n));
  }
  return 0;
}
