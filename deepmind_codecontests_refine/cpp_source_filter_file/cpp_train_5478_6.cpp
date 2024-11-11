#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i;
  int fl = 0, gl = 0;
  set<int> s;
  cin >> n;
  int a[n + 2];
  for (i = 1; i <= n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a + 1, a + 1 + n);
  if (s.size() == 2) {
    if (a[i] == a[n / 2] && a[n / 2 + 1] == a[n] && a[1] != a[n]) {
      cout << "YES\n" << a[1] << " " << a[n / 2 + 1];
    } else
      cout << "NO";
  } else
    cout << "NO";
  return 0;
}
