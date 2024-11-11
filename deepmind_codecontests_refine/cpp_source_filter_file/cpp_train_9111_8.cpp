#include <bits/stdc++.h>
using namespace std;
int n, cnt1, a[1002];
bool prim(int n) {
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) return 0;
  return 1;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    cnt1 += (a[i] == 1);
  }
  if (cnt1)
    for (int i = 1; i <= n; i++)
      if (a[i] != 1 && prim(a[i] + 1)) {
        cout << cnt1 + 1 << "\n";
        while (cnt1--) cout << "1 ";
        cout << a[i];
        return 0;
      }
  if (cnt1 > 1) {
    cout << cnt1 << "\n";
    while (cnt1--) cout << "1 ";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++)
      if (prim(a[i] + a[j])) {
        cout << 2 << "\n";
        cout << a[i] << " " << a[j];
        return 0;
      }
  }
  cout << "1 \n " << a[0];
  return 0;
}
