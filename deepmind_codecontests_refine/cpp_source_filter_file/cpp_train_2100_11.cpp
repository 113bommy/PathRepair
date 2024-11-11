#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
long long a[maxn], sum[maxn], d[maxn];
struct node {
  int d, g;
} p[maxn];
bool cmp(node a, node b) { return a.d < b.d; }
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= m; i++) cin >> p[i].d >> p[i].g;
  sort(p + 1, p + 1 + n, cmp);
  for (int i = 1; i <= m; i++) {
    d[i] = p[i].d;
    sum[i] = sum[i - 1] + p[i].g;
  }
  for (int i = 1; i <= n; i++) {
    int index = lower_bound(d, d + m + 1, a[i]) - d;
    cout << sum[index - 1] << " ";
  }
  cout << endl;
}
