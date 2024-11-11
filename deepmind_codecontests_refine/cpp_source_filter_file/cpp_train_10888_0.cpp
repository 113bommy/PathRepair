#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;
int ar[MAXN];
int main() {
  ios::sync_with_stdio(false);
  int n, m, k;
  cin >> n >> m >> k;
  int a, b, cur;
  bool kai = 0;
  for (int i = 0; i < m; i++) {
    cin >> ar[i];
    if (ar[i] == 1) kai = 1;
  }
  sort(ar, ar + m);
  cur = 1;
  while (k--) {
    cin >> a >> b;
    if (kai) continue;
    if (a == cur) {
      cur = b;
      int ind = lower_bound(ar, ar + m, b) - ar;
      if (ind < m && ar[ind] == b) kai = 1;
    } else if (b == cur) {
      cur = a;
      int ind = lower_bound(ar, ar + m, a) - ar;
      if (ind < m && ar[ind] == b) kai = 1;
    }
  }
  cout << cur << endl;
}
