#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  bool mk[n + 1];
  for (int i = 1; i < n; i++) {
    mk[i] = 0;
    cin >> a[i];
  }
  mk[n] = 0;
  int root = a[1];
  cout << root + 1 << endl;
  int cur = n;
  for (int i = 1; i < n; i++) {
    mk[a[i]] = 1;
    while (mk[cur]) cur--;
    if (i == n - 1 || mk[a[i + 1]]) {
      cout << a[i] << " " << cur << '\n';
      mk[cur] = 1;
    } else
      cout << a[i + 1] << " " << a[i] << '\n';
  }
  return 0;
}
