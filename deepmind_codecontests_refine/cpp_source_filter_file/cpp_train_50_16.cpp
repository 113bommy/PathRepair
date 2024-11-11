#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, a[110];
  cin >> n >> m;
  for (int i = 0; i <= n; i++) a[i] = 0;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    for (int j = 0; j < temp; j++) {
      int x;
      cin >> x;
      a[x] = 1;
    }
  }
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == 0) res = 1;
  if (res == 1)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
