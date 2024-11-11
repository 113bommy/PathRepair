#include <bits/stdc++.h>
using namespace std;
int x[200010];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int judge = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x[i]);
    }
    for (int i = 2; i <= n; i++) {
      if (x[i] != x[i - 1]) {
        judge = 1;
        break;
      }
    }
    if (judge == 1)
      cout << n << endl;
    else
      cout << 1 << endl;
  }
  return 0;
}
