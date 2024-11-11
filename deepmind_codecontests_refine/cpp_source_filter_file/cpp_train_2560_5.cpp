#include <bits/stdc++.h>
using namespace std;
struct Node {
  int v, id, res;
} a[105];
bool cmp1(Node x, Node y) { return x.v > y.v; }
bool cmp2(Node x, Node y) { return x.id < y.id; }
int main() {
  int n, w, used = 0;
  cin >> n >> w;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].v;
    a[i].id = w;
    a[i].res = a[i].v / 2 + a[i].v % 2;
    used += a[i].res;
  }
  if (used > w)
    cout << -1 << endl;
  else {
    sort(a + 1, a + 1 + n, cmp1);
    for (int i = 1; i <= n; i++) {
      if (w - used < a[i].v - a[i].res) {
        a[i].res += w - used;
        break;
      } else {
        used += a[i].v - a[i].res;
        a[i].res = a[i].v;
      }
    }
    sort(a + 1, a + 1 + n, cmp2);
    for (int i = 1; i < n; i++) {
      cout << a[i].res << " ";
    }
    cout << a[n].res << endl;
  }
  return 0;
}
