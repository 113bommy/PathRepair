#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3f;
const int MOD1 = 1e9 + 7, MOD2 = 1e9 + 9;
int k;
set<pair<int, int> > inc;
void put(pair<int, int> a) {
  if (inc.find(pair<int, int>(a.second, a.first)) == inc.end()) inc.insert(a);
}
void solve(int f) {
  for (int i = f + 1; i <= f + k - 1; i++) put(pair<int, int>(f, i));
  for (int i = f + 1; i <= k + f - 1; i++) {
    for (int j = f + 1; j <= f + k - 1; j++) {
      if (i + j == 2 * f + k or i == j) continue;
      put(pair<int, int>(i, j));
    }
  }
  put(pair<int, int>(k + f, k + f + 1));
  for (int i = f + 1; i <= k + f - 1; i++) {
    put(pair<int, int>(i, k + f));
    put(pair<int, int>(i, k + f + 1));
  }
}
int main() {
  scanf("%d", &k);
  if (k == 1) {
    puts("YES");
    printf("2 1\n1 2\n");
    return 0;
  }
  if (k % 2 == 0) puts("NO"), exit(0);
  solve(1);
  put(pair<int, int>(1, k + 3));
  solve(k + 3);
  puts("YES");
  printf("%d %d\n", 2 * k + 4, k * (2 * k + 4) / 2);
  for (auto x : inc) printf("%d %d\n", x.first, x.second);
}
