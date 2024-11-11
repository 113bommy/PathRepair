#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], b[N], x;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> x;
    b[x] = i;
  }
  for (int i = 1; i <= n; i++) {
    a[i] = b[a[i]];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] > a[i + 1]) {
      return cout << n - i, 0;
    }
  }
}
