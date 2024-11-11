#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int INF = 0x3f3f3f3f;
int n, a[MAXN];
vector<int> ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    if (i != 1 && a[i] == 1) ans.push_back(a[i - 1]);
  }
  ans.push_back(a[n]);
  printf("%d\n", ans.size());
  for (auto i : ans) printf("%d ", i);
  return 0;
}
