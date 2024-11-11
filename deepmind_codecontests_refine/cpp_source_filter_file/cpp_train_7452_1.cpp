#include <bits/stdc++.h>
using namespace std;
int n, m, k;
unordered_map<int, int> sgfunc;
int sg(int x) {
  if (sgfunc.count(x)) return sgfunc[x];
  if (x < k) return -1;
  unordered_map<int, bool> mp;
  for (int i = 1; i * i <= x; i++) {
    if (x % i != 0) continue;
    if (i != x) mp[sg(i)] = true;
    if (i != 1) mp[sg(x / i)] = true;
  }
  for (int i = 0;; i++)
    if (!mp[i]) {
      sgfunc[x] = i;
      return i;
    }
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (!(n & 1)) {
    printf("Marsel\n");
    return 0;
  }
  if (m <= k) {
    printf("Marsel\n");
  }
  if (sg(m)) {
    printf("Timur\n");
  } else {
    printf("Marsel\n");
  }
  return 0;
}
