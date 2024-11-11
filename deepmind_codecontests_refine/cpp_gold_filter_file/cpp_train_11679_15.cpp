#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
  int d;
  int idx;
  bool operator<(const Node &t) const { return d > t.d; }
} a[100010];
int b[200010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].idx = i;
    cin >> a[i].d;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) b[i] = 2 * a[i].idx - 1;
  for (int i = 1; i < n; i++) cout << b[i] << " " << b[i + 1] << endl;
  for (int i = 1; i <= n; i++) {
    if (b[i + a[i].d] == 0) {
      b[i + a[i].d] = 2 * a[i].idx;
      cout << b[i + a[i].d - 1] << " " << b[i + a[i].d] << endl;
    } else {
      cout << b[i + a[i].d - 1] << " " << 2 * a[i].idx << endl;
    }
  }
}
