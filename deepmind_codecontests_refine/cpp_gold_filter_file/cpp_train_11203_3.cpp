#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int inf = 1e9 + 7;
int a[N], ans[N];
pair<int, int> coe[N];
inline int ab(int x) { return x < 0 ? -x : x; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) scanf("%d", &a[i]);
  for (int i = (1); i <= (n - 1); i++) coe[i].first = (n - a[i]) - a[i + 1];
  coe[n].first = (n - a[n]) - a[1];
  for (int i = (1); i <= (n); i++) coe[i].second = i;
  sort(coe + 1, coe + 1 + n);
  for (int i = (1); i <= (n); i++) ans[coe[i].second] = i - 1;
  for (int i = (1); i <= (n); i++) printf("%d ", n - ans[i] - 1);
  puts("");
  return 0;
}
