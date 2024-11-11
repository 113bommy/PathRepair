#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int a[maxn * 2];
int main() {
  int n, cnt = 0;
  cin >> n;
  if (n & 1) {
    puts("YES");
    for (int i = 1; i <= n; i++) {
      if (i & 1)
        a[i] = ++cnt, a[i + n] = ++cnt;
      else
        a[i + 1] = ++cnt, a[i] = ++cnt;
    }
    for (int i = 1; i <= 2 * n; i++) cout << a[i] << " ";
    cout << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
