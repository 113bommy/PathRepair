#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n, i, j, x1, y1, x2, y2, a1, a2, a3, a4, ok = 1, p;
  cin >> n;
  int g[n + 1][n + 1];
  g[1][1] = 1;
  g[n][n] = 0;
  cout << "? 1 1 2 2"
       << "\n";
  cout.flush();
  cin >> t;
  if (t == 1) {
    g[2][2] = 1;
  } else {
    g[2][2] = 0;
  }
  g[1][2] = 1;
  cout << "? 1 2 2 3"
       << "\n";
  cout.flush();
  cin >> t;
  if (t == 1) {
    g[2][3] = 1;
  } else {
    g[2][3] = 0;
  }
  cout << "? 2 1 2 3"
       << "\n";
  cout.flush();
  cin >> t;
  if (t == 1) {
    g[2][1] = g[2][3];
  } else {
    g[2][1] = g[2][3] ^ 1;
  }
  for (i = 3; i <= n; i++) {
    cout << "? 1 " << i - 2 << " 1 " << i << "\n";
    cout.flush();
    cin >> t;
    g[1][i] = g[1][i - 2];
    if (t == 0) {
      g[1][i] ^= 1;
    }
  }
  for (i = 4; i <= n; i++) {
    cout << "? 2 " << i - 2 << "2 " << i << "\n";
    cout.flush();
    cin >> t;
    g[2][i] = g[2][i - 2];
    if (t == 0) g[2][i] ^= 1;
  }
  for (i = 3; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      g[i][j] = g[i - 2][j];
      cout << "? " << i - 2 << " " << j << " " << i << " " << j << "\n";
      cout.flush();
      cin >> t;
      if (t == 0) {
        g[i][j] ^= 1;
      }
    }
  }
  vector<int> v;
  for (i = 1; i <= n; i++) {
    v.push_back(1);
    v.push_back(i);
  }
  for (i = 2; i <= n; i++) {
    v.push_back(i);
    v.push_back(n);
  }
  for (i = 7; i < 2 * n; i += 2) {
    j = i;
    x2 = v[j - 1];
    y2 = v[j];
    a1 = g[v[j - 1]][v[j]];
    j -= 2;
    a2 = g[v[j - 1]][v[j]];
    j -= 2;
    a3 = g[v[j - 1]][v[j]];
    j -= 2;
    a4 = g[v[j - 1]][v[j]];
    x1 = v[j - 1];
    y1 = v[j];
    if (a1 ^ a2 ^ a3 ^ a4) continue;
    p = 0;
    if (a4 == a1) p = 1;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
    cout.flush();
    cin >> t;
    if (t != p) ok = 0;
    break;
  }
  if (ok) {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= n; j++) {
        if (i % 2 == j % 2) continue;
        g[i][j] ^= 1;
      }
    }
  }
  cout << "!\n";
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      cout << g[i][j];
    }
    cout << "\n";
  }
  return 0;
}
