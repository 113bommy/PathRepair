#include <bits/stdc++.h>
using namespace std;
void fun(int num, int n) {
  for (int j = 1; j <= n; j++) {
    for (int i = 1; i <= n; i++) {
      if (!num) return;
      if (i - j > 0) {
        cout << i << " " << i - j << endl;
        num--;
      }
    }
  }
}
int main() {
  int t, n, p;
  cin >> t;
  while (t--) {
    cin >> n >> p;
    int num = 2 * n + p;
    fun(num, n);
  }
  return 0;
}
