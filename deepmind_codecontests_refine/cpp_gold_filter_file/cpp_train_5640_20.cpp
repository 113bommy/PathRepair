#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y;
  int a[100005];
  bool v = true;
  memset(a, 0, sizeof(a));
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> x >> y;
    a[x]++;
    a[y]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 2) v = false;
  }
  if (v)
    cout << "YES";
  else {
    cout << "NO";
  }
  return 0;
}
