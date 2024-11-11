#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  long long int s = 0;
  cin >> n >> k;
  int a[n];
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    s += min(a[x], a[y]);
  }
  cout << s;
  return 0;
}
