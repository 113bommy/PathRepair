#include <bits/stdc++.h>
using namespace std;
int seg[2 * (1 << 18)];
void init() { fill(seg, seg + 2 * (1 << 18), (1 << 25)); }
void add(int x, int a) {
  x += (1 << 18) - 1;
  while (x) {
    seg[x] = min(seg[x], a);
    x /= 2;
  }
}
int get(int l, int r, int k = 1, int a = 1, int b = (1 << 18)) {
  if (l <= a && b <= r) return seg[k];
  if (l > b || r < a) return (1 << 25);
  return min(get(l, min(r, (a + b) / 2), k * 2, a, (a + b) / 2),
             get(max(l, (a + b + 1) / 2), r, k * 2 + 1, (a + b + 1) / 2, b));
}
int a[100000];
int r[100000];
int main() {
  init();
  int n;
  cin >> n;
  vector<int> u;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    u.push_back(a[i]);
  }
  sort(u.begin(), u.end());
  u.erase(unique(u.begin(), u.end()), u.end());
  for (int i = 0; i < n; i++)
    a[i] = (lower_bound(u.begin(), u.end(), a[i]) - u.begin()) + 1;
  reverse(a, a + n);
  for (int i = 0; i < n; i++) {
    int g = get(1, a[i] - 1);
    if (g == (1 << 25))
      r[i] = -1;
    else
      r[i] = i - g - 1;
    add(a[i], i);
  }
  for (int i = n - 1; i >= 0; i--) cout << r[i] << " ";
  cout << endl;
}
