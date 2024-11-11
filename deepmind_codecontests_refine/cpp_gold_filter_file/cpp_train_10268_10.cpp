#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 10;
int a[MAXN], b[MAXN];
int l[MAXN], r[MAXN];
long long ans;
vector<int> v;
void print(int x, int p) {
  if (!p) return;
  if (l[p - 1] <= x + 1 && x + 1 <= r[p - 1])
    print(x + 1, p - 1);
  else if (l[p - 1] <= x && x <= r[p - 1])
    print(x, p - 1);
  else
    print(x - 1, p - 1);
  ans += x - a[p];
  v.push_back(x);
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%d%d", &a[i], &b[i]);
  l[1] = a[1], r[1] = a[1] + b[1];
  int ok = 1;
  for (int i = 2; i <= n; i++) {
    l[i] = max(a[i], l[i - 1] - 1);
    r[i] = min(a[i] + b[i], r[i - 1] + 1);
    if (r[i] < l[i]) {
      ok = 0;
      break;
    }
  }
  if (!ok)
    cout << -1 << endl;
  else {
    print(r[n], n);
    cout << ans << endl;
    for (auto i : v) printf("%d ", i);
  }
}
