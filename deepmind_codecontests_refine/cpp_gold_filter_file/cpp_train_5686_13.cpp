#include <bits/stdc++.h>
using namespace std;
int f[400009], pos[400009], n;
struct node {
  int x, y;
} k[200009];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i].x >> k[i].y;
    pos[i << 1] = k[i].x;
    pos[(i << 1) - 1] = k[i].y;
  }
  sort(pos + 1, pos + n + n + 1);
  int u = unique(pos + 1, pos + n + n + 1) - pos - 1;
  for (int i = 1; i <= n; i++) {
    k[i].x = lower_bound(pos + 1, pos + u + 1, k[i].x) - pos;
    k[i].y = lower_bound(pos + 1, pos + u + 1, k[i].y) - pos;
    f[k[i].x]++;
    f[k[i].y + 1]--;
  }
  int tot = 0;
  for (int i = 1; i <= u; i++) {
    tot += f[i];
    if (tot > 2) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}
