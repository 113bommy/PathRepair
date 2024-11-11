#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int a[100100];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  for (int i = 1; i <= n; i++) {
    s = s + i;
    if (s > m) {
      cout << i - 1;
      return 0;
    }
  }
  cout << n;
}
