#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
int n, m, cnt, tot;
int a[maxn], b[maxn], ban[maxn], l[maxn], top, pos;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = (1); i <= (n); ++i) cin >> a[i];
  for (int i = (1); i <= (m); ++i) cin >> b[i], ban[b[i]] = 1;
  sort(b + 1, b + m + 1);
  for (int i = (2); i <= (m); ++i) {
    if (b[i] - b[i - 1] > a[b[i]] - a[b[i - 1]]) {
      puts("-1");
      return 0;
    }
  }
  for (int i = (1); i <= (n); ++i) a[i] -= i;
  for (int i = (1); i <= (n); ++i) {
    if (top == 0 || l[top] <= a[i]) {
      l[++top] = a[i];
      if (ban[i]) pos = top;
    } else {
      int p = upper_bound(l + 1, l + top + 1, a[i]) - l;
      if (p <= pos) continue;
      l[p] = a[i];
      if (ban[i]) pos = p, top = p;
    }
  }
  cout << n - top << endl;
  return 0;
}
