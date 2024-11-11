#include <bits/stdc++.h>
using namespace std;
int main() {
  long long arr[100009];
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int a, b, c, d = 0;
  while (m--) {
    cin >> a >> b;
    if (a == 1) {
      cin >> c;
      arr[b] = c - d;
    } else if (a == 2) {
      d += b;
    } else {
      cout << arr[b] + d << endl;
    }
  }
  return 0;
}
