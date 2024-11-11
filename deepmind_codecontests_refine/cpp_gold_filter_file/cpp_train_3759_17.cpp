#include <bits/stdc++.h>
const double Pi = acos(-1.0);
using namespace std;
const int maxN = 200005;
int n, m, y;
int a[maxN], b[maxN];
int main(int argc, char** argv) {
  scanf("%d %d", &n, &y);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  scanf("%d %d", &m, &y);
  for (int i = 0; i < m; i++) scanf("%d", &b[i]);
  int ans = 2;
  for (int i = 0; i < 30; i++) {
    map<int, int> cnt;
    for (int j = 0; j < n; j++) cnt[(a[j] + (1 << i)) % (2 << i)]++;
    for (int j = 0; j < m; j++) cnt[b[j] % (2 << i)]++;
    for (map<int, int>::iterator it = cnt.begin(); it != cnt.end(); it++)
      ans = max(ans, (*it).second);
  }
  printf("%d\n", ans);
  return 0;
}
