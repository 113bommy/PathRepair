#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, s;
  cin >> n >> s;
  s--;
  bool a[n], b[n];
  bool ok = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  if (a[0] and b[s]) {
    for (int i = s; i < n; i++) {
      if (a[i] and b[i]) {
        ok = true;
      }
    }
  }
  if (a[0] and a[s]) ok = true;
  if (ok == true)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
