#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 2e6 + 25;
struct node {
  int v, pos;
} a[maxn];
bool cmp(node a, node b) { return a.v < b.v; }
int n, b[maxn];
bool check(int x) {
  int len = 1;
  for (int i = 1; i <= n; ++i) {
    if (i != x) b[len++] = a[i].v;
  }
  int d = b[2] - b[1];
  for (int i = 3; i < len; ++i)
    if (b[i] - b[i - 1] != d) return false;
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i].v, a[i].pos = i;
  if (n <= 3) {
    cout << 1;
    return 0;
  }
  sort(a + 1, a + n + 1, cmp);
  int d = a[2].v - a[1].v;
  for (int i = 3; i <= n; ++i) {
    if (a[i].v - a[i - 1].v != d) {
      if (check(i - 2)) {
        cout << a[i - 2].pos;
        return 0;
      }
      if (check(i - 1)) {
        cout << a[i - 1].pos;
        return 0;
      }
      if (check(i)) {
        cout << a[i].pos;
        return 0;
      }
      cout << -1;
      return 0;
    }
  }
  cout << a[1].pos;
  return 0;
}
