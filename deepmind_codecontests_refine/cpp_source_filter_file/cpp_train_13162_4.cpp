#include <bits/stdc++.h>
using namespace std;
int n, h, s, c, mx;
int main() {
  cin >> n >> h;
  for (int i = 0; i < n; i++) {
    cin >> c;
    if (mx < c) mx = c;
    s += c;
  }
  if (s - c <= h) {
    cout << "YES";
  } else
    cout << "NO";
  return 0;
}
