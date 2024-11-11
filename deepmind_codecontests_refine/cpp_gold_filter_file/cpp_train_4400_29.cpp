#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int i, a[n + 1], x;
  for (i = 1; i <= n; ++i) {
    cin >> x;
    a[x] = i;
  }
  for (i = 1; i <= n; ++i) cout << a[i] << " ";
}
