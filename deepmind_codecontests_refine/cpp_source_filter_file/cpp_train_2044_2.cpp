#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 5;
int a[maxn];
int main() {
  ios::sync_with_stdio(0);
  long long n;
  while (cin >> n) {
    if (n % 2 == 0) {
      if (n % 4 == 0) {
        cout << 0 << endl << n / 2 << " ";
        for (int i = 1; i <= n / 4; i++) cout << i << " " << n - i + 1 << " ";
      } else {
        cout << 1 << endl << n / 2 << " ";
        for (int i = 1; i <= n / 4; i++) cout << i << " " << n - i + 1 << " ";
        cout << n / 2;
      }
    } else {
      if ((n * (n + 1) / 2) % 2 == 0) {
        cout << 0 << endl;
        cout << n / 2 + 1 << " ";
        for (int i = 1; i <= n / 2 + 1; i += 2) cout << i << " ";
        for (int i = n / 2 + 1; i <= n; i += 2) cout << i << " ";
      } else {
        cout << 0 << endl;
        cout << n / 2 + 1 << " ";
        for (int i = 1; i <= n / 2 + 1; i += 2) cout << i << " ";
        for (int i = n / 2 + 2; i <= n; i += 2) cout << i << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
