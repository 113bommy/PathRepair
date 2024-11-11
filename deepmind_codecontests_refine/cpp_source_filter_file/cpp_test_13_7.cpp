#include <bits/stdc++.h>
using namespace std;
int n, i, j, da, db, dc;
string a;
int main() {
  cin >> n;
  for (i = 0; i < n; ++i) {
    cin >> a;
    da = 0;
    db = 0;
    dc = 0;
    for (j = 0; j < a.size(); ++j) {
      if (a[j] == 'A') ++da;
      if (a[j] == 'B') ++db;
      if (a[j] == 'C') ++dc;
    }
    if (da + dc == db)
      cout << "YES";
    else
      cout << "NO";
  }
}
