#include <bits/stdc++.h>
using namespace std;
char ch;
int n, ans = 0;
string s;
int main() {
  cin >> n;
  vector<int> q(n);
  for (int i = 0; i < n; i++) cin >> q[i];
  bool ok = true;
  int diff = 1e9;
  for (int i = 1; i < n; i++) {
    int tdiff = abs(q[i] - q[i - 1]);
    if (tdiff == 0) ok = false;
    if (tdiff != 1) diff = tdiff;
  }
  for (int i = 1; i < n && ok; i++) {
    int tdiff = abs(q[i] - q[i - 1]);
    if (tdiff == 1) {
      if (min(q[i], q[i - 1]) % diff == 0) ok = false;
    } else if (tdiff != diff) {
      ok = false;
    }
  }
  if (ok) {
    cout << "YES\n" << (int)1e9 << ' ' << diff;
  } else {
    cout << "NO";
  }
}
