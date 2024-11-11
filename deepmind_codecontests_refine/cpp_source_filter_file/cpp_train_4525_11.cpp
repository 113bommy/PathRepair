#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[2001];
int f[2000], ok, n, px, ok2;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].first;
    a[i].second = i;
    f[a[i].first]++;
    if (f[a[i].first] == 2) ok++;
    if (f[a[i].first] == 4) ok2++;
  }
  if (ok < 2 && ok2 == 0)
    cout << "NO";
  else {
    cout << "YES\n";
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++) {
      cout << a[i].second << " ";
      if (f[a[i].first] >= 2) {
        px = i;
      }
    }
    cout << "\n";
    swap(a[px], a[px - 1]);
    for (int i = 1; i <= n; i++) {
      cout << a[i].second << " ";
    }
    for (int i = 1; i <= n; i++) {
      if (f[a[i].first] >= 2) {
        px = i;
        break;
      }
    }
    cout << "\n";
    swap(a[px], a[px + 1]);
    for (int i = 1; i <= n; i++) {
      cout << a[i].second << " ";
    }
  }
  return 0;
}
