#include <bits/stdc++.h>
using namespace std;
int main() {
  const int x = 1000;
  int a[x], b[x], e;
  string h, r, m;
  cin >> h >> r >> m;
  for (int i = 0; i < x; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  for (int i = 0; i < h.size(); i++) {
    a[h[i]]++;
  }
  for (int i = 0; i < r.size(); i++) {
    a[r[i]]++;
  }
  for (int i = 0; i < m.size(); i++) {
    b[m[i]]++;
  }
  for (int i = 'A'; i <= 'Z'; i++) {
    if (a[i] != b[i]) {
      e++;
      break;
    }
  }
  if (e == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
