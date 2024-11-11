#include <bits/stdc++.h>
using namespace std;
int n, k, a[1000006];
int c;
int pre[] = {0, 1, 0, 1, 2};
int gr(int x) {
  if (k) {
    if (x < 5) return pre[x];
    if (x % 2) return 0;
    return gr(x / 2) + 1;
  } else {
    if (x < 3) return x;
    return !x % 2;
  }
}
int main() {
  cin >> n >> k;
  k %= 2;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) {
    c ^= gr(a[i]);
  }
  cout << (c ? "Kevin" : "Nicky") << "\n";
  return 0;
}
