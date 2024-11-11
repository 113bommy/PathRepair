#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
vector<int> ans[maxn + 5];
int c[maxn + 5];
int n, a[maxn + 5];
int lowbit(int x) { return x & -x; }
void add(int x) {
  while (x <= n) {
    c[x]++;
    x += lowbit(x);
  }
}
int sum(int x) {
  int res = 0;
  while (x > 0) {
    res += c[x];
    x -= lowbit(x);
  }
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    ans[min(a[i], i - 1)].push_back(i);
  }
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = min(a[i], n);
    add(a[i]);
    for (int j = 0; j < ans[i].size(); j++) {
      res += (long long)(sum(n) - sum(ans[i][j] - 1));
    }
  }
  printf("%lld\n", res);
  return 0;
}
