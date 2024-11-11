#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const int bb = 13331;
int a, b, c, d, n, m;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> m;
  int q[maxn];
  while (m--) {
    cin >> n;
    a = 0;
    for (int i = 1; i <= n; i++) cin >> q[i];
    b = q[n];
    for (int i = n - 1; i > 0; i--) {
      if (q[i] < b)
        b = q[i];
      else
        a++;
    }
    cout << a << endl;
  }
}
