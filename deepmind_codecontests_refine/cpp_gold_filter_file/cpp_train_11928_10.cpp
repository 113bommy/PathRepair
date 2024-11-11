#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  int c, d;
  cin >> c >> d;
  int l = 0, r = 0;
  int fl = 1;
  if (d == 2) fl = 0;
  int flag = 1;
  if (d == 1)
    l = 1900, r = 100000000;
  else
    l = -100000000, r = 1899;
  for (int i = 1; i < n; i++) {
    int s, d;
    cin >> s >> d;
    if (d == 2) fl = 0;
    l = l + c;
    r = r + c;
    if (d == 1) {
      l = max(l, 1900);
      if (r < 1900) flag = -1;
    } else {
      r = min(r, 1899);
      if (l >= 1900) flag = -1;
    }
    c = s;
  }
  if (fl == 1)
    cout << "Infinity";
  else if (flag == -1)
    cout << "Impossible";
  else
    cout << (r + c);
}
