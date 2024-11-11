#include <bits/stdc++.h>
using namespace std;
int n, q, t, p, x;
vector<int> a, l, mx;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  a.resize(n);
  l.resize(n);
  for (int i = (0); i < (n); i++) cin >> a[i];
  cin >> q;
  mx.resize(q);
  for (int i = (0); i < (q); i++) {
    cin >> t;
    if (t == 1) {
      cin >> p >> x;
      a[p - 1] = x;
      l[p - 1] = i;
    } else {
      cin >> x;
      mx[i] = x;
    }
  }
  for (int i = n - 2; i >= 0; i--) mx[i] = max(mx[i], mx[i + 1]);
  for (int i = (0); i < (l.size()); i++) a[i] = max(mx[l[i]], a[i]);
  for (int i = (0); i < (n); i++) cout << a[i] << " ";
  return 0;
}
