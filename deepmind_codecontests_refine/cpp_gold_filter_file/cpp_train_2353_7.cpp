#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const double eps = 1e-6;
const int inf = 0x3f3f3f3f;
const double pi = acos(-1.0);
const int maxn = 200000 + 5;
int C[maxn], pre[maxn];
int lowbit(int x) { return (-x) & x; }
void update(int x, int y) {
  for (int i = x; i > 0; i -= lowbit(i)) C[i] += y;
}
int query(int x) {
  int s = 0;
  for (int k = x; k <= 200000; k += lowbit(k)) s += C[k];
  return s;
}
int main() {
  int n, k, q, a, b;
  cin >> n >> k >> q;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    update(b, 1);
    update(a - 1, -1);
  }
  for (int i = 1; i <= 200000; i++) {
    int x = query(i);
    pre[i] = pre[i - 1] + (x >= k);
  }
  while (q--) {
    cin >> a >> b;
    cout << pre[b] - pre[a - 1] << endl;
  }
  return 0;
}
