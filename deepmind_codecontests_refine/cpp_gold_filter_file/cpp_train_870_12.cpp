#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    if (a == 0) {
      ar[a + 1] += ar[a] - b;
      ar[a] = 0;
    } else if (a == n - 1) {
      ar[a - 1] += b - 1;
      ar[a] = 0;
    } else {
      ar[a + 1] += ar[a] - b;
      ar[a - 1] += b - 1;
      ar[a] = 0;
    }
  }
  for (int i = 0; i < n; i++) cout << ar[i] << endl;
  return 0;
}
