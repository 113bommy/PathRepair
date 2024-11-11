#include <bits/stdc++.h>
using namespace std;
vector<int> g;
int a[100005], b[100005], c[100005];
int n, k;
void solve() {
  int i, j, m, ans, cnt;
  c[m = 0] = a[0];
  for (i = 1; i < n; i++)
    if (a[i] != a[i - 1]) c[++m] = a[i];
  b[a[0]]--;
  for (i = 1; i <= m; i++) {
    b[a[i]]--;
    if (a[i - 1] == a[i + 1]) b[a[i]]--;
  }
  j = 1;
  for (i = 1; i <= k; i++)
    if (b[j] > b[i]) j = i;
  cout << j << endl;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  solve();
  return 0;
}
