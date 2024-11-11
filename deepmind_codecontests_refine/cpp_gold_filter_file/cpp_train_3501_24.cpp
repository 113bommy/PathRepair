#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 7;
int a[M];
int main() {
  int n, m;
  cin >> n >> m;
  char ch[n + 5];
  for (int i = 1; i <= n; i++) cin >> ch[i];
  int l, r;
  char c1, c2;
  for (int k = 0; k < m; k++) {
    cin >> l >> r >> c1 >> c2;
    for (int i = l; i <= r; i++) {
      if (ch[i] == c1) ch[i] = c2;
    }
  }
  for (int i = 0; i < n; i++) cout << ch[i + 1];
  cout << endl;
  return 0;
}
