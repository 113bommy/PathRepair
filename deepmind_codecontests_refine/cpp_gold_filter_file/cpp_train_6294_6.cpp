#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c, mx1, mx2, mx3;
  cin >> a >> b >> c;
  if (a[1] == '<') reverse(a.begin(), a.end());
  if (b[1] == '<') reverse(b.begin(), b.end());
  if (c[1] == '<') reverse(c.begin(), c.end());
  if (a[0] == b[0] || a[0] == c[0]) {
    mx1 = a[0];
    if (a[0] != b[0])
      mx2 = b[0];
    else if (a[0] != c[0])
      mx2 = c[0];
    if (a[2] != mx2[0]) mx3 = a[2];
    if (b[2] != mx2[0]) mx3 = b[2];
    if (c[2] != mx2[0]) mx3 = c[2];
  } else if (b[0] == c[0]) {
    mx1 = b[0];
    mx2 = a[0];
    if (a[2] != mx2[0]) mx3 = a[2];
    if (b[2] != mx2[0]) mx3 = b[2];
    if (c[2] != mx2[0]) mx3 = c[2];
  } else {
    cout << "Impossible" << endl;
    return 0;
  }
  cout << mx3 << mx2 << mx1 << endl;
}
