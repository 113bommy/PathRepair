#include <bits/stdc++.h>
using namespace std;
int a[100005], n;
void update(int i, int v) {
  for (; i < n; i = i | (i + 1)) a[i] = max(a[i], v);
}
int get(int i) {
  int len = 0;
  for (; i >= 0; i = (i & (i + 1)) - 1) len = max(len, a[i]);
  return len;
}
int main() {
  int mx, x, i, ans = 0;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    mx = get(x - 1);
    update(x, mx + 1);
    ans = max(ans, mx + 1);
  }
  cout << ans;
  return 0;
}
