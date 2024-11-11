#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
using namespace std;
int n;
int kek[200001];
pair<int, int> get(int l, int r) {
  cout << "? " << l << ' ' << r << endl;
  int x, f;
  cin >> x >> f;
  return {x, f};
}
void put(int k) {
  pair<int, int> pr = get(k, k);
  kek[k] = pr.first;
}
void ask(int l, int r) {
  if (l > r) {
    return;
  }
  if (kek[l] != -1) {
    return;
  }
  if (l == r) {
    put(l);
  } else {
    pair<int, int> pr = get(l, r);
    int x = pr.first;
    int f = pr.second;
    if (x == kek[l - 1]) {
      for (int i = l; i < l + f; i++) {
        kek[i] = x;
      }
      ask(l + f, r);
    } else if (x == kek[r + 1]) {
      for (int i = r; i > r - f; i--) {
        kek[i] = x;
      }
      ask(l, r - f);
    } else {
      int m = (l + r) >> 1;
      if (f > (r - l) >> 1) {
        m = x;
      } else {
        put(m);
      }
      ask(l, m - 1);
      ask(m + 1, r);
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    kek[i] = -1;
  }
  put(1);
  put(n);
  ask(2, n - 1);
  cout << "! ";
  for (int i = 1; i <= n; i++) {
    cout << kek[i] << ' ';
  }
  cout << endl;
  fflush(stdout);
  return 0;
}
