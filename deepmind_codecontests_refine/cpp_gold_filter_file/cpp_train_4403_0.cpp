#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int a[N];
int t, n;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int num1 = 0, flag1 = 0, flag2 = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 0) num1++;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 1) {
        flag1 = i;
        break;
      }
    }
    for (int i = n; i >= 1; i--) {
      if (a[i] == 1) {
        flag2 = n - i;
        break;
      }
    }
    cout << num1 - flag1 - flag2 + 1 << endl;
  }
  return 0;
}
