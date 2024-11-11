#include <bits/stdc++.h>
using namespace std;
int n, w, a[200010], b[200010], t[200010];
void build_table() {
  t[0] = -1;
  t[1] = 0;
  int i = 2;
  int x = 0;
  while (i <= w) {
    if (b[i - 1] == b[x])
      t[i++] = ++x;
    else if (x > 0)
      x = t[x];
    else {
      i++;
      x = 0;
    }
  }
}
int kmp() {
  int ans = 0;
  int i = 0;
  int x = 0;
  while (i + x < n) {
    if (x < w && a[i + x] == b[x]) {
      x++;
      if (x == w) ans++;
    } else {
      i += x - t[x];
      x = max(t[x], 0);
    }
  }
  return ans;
}
int main() {
  cin >> n >> w;
  if (w == 1) {
    cout << n << '\n';
    return 0;
  }
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < w; i++) cin >> b[i];
  n--;
  w--;
  for (int i = 0; i < n; i++) a[i] = a[i + 1] - a[i];
  for (int i = 0; i < w; i++) b[i] = b[i + 1] - b[i];
  build_table();
  cout << kmp() << '\n';
}
