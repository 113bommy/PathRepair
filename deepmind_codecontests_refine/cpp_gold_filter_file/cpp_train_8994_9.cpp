#include <bits/stdc++.h>
using namespace std;
int dirty[3009];
int main() {
  int n, m;
  cin >> n >> m;
  for (typeof(0) i = (0); i < (m); i++) cin >> dirty[i];
  sort(dirty, dirty + m);
  if (!m)
    cout << "YES\n";
  else if ((dirty[0] != 1) && (dirty[m - 1] != n)) {
    if (m < 3)
      cout << "YES\n";
    else {
      bool YES = true;
      for (typeof(0) i = (0); i < (m - 2); i++)
        if ((dirty[i] == (dirty[i + 1] - 1)) &&
            (dirty[i + 1] == (dirty[i + 2] - 1)))
          YES = false;
      if (YES)
        cout << "YES\n";
      else
        cout << "NO\n";
    }
  } else
    cout << "NO\n";
  return 0;
}
