#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x = 0;
  cin >> n;
  string f[n];
  string l[n];
  string lt = "a";
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> f[i] >> l[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] -= 1;
  }
  for (int i = 0; i < n; i++) {
    if (f[a[i]].compare(lt) >= 0 &&
        (l[a[i]].compare(f[a[i]]) >= 0 or l[a[i]].compare(lt) <= 0))
      lt = f[a[i]];
    else if (l[a[i]].compare(lt) >= 0)
      lt = l[a[i]];
    else if (f[a[i]].compare(lt) <= 0 && l[a[i]].compare(lt) <= 0) {
      x = 1;
      break;
    }
  }
  if (x == 0)
    cout << "YES";
  else
    cout << "NO";
}
