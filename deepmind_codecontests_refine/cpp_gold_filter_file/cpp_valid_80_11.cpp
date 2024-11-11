#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  string str;
  scanf("%d", &n);
  cin >> str;
  for (int i = 0; i < n; i++) {
    if (str[i] == '0') {
      if (i < (n / 2)) {
        printf("%d %d %d %d", i + 1, n, i + 2, n);
      } else {
        printf("%d %d %d %d", 1, i + 1, 1, i);
      }
      return;
    }
  }
  printf("%d %d %d %d", 1, n - 1, 2, n);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
    cout << "\n";
  }
  return 0;
}
