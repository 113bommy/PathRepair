#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 23;
int a[maxn];
pair<int, int> b[maxn];
int main() {
  int n, p;
  cin >> n >> p;
  for (int i = 0; i < n; i++) scanf("%d", a + i);
  sort(a, a + n);
  int x = a[n - 1] - n + 1;
  for (int i = 0; i < n; i++) {
    x = max(x, a[i] - i);
  }
  int d = INT_MAX;
  for (int i = 0, j = 0; i + p - 1 < n; i++, j++) {
    d = min(d, a[i + p - 1] - j);
  }
  vector<int> ans;
  for (int i = x; i < d; i++) {
    ans.push_back(i);
  }
  cout << ans.size() << '\n';
  for (int i : ans) printf("%d ", i);
}
