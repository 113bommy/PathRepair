#include <bits/stdc++.h>
using namespace std;
int b[100];
int g[100];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < 100; i++) b[i] = g[i] = 0;
  int bHap, gHap, c;
  cin >> bHap;
  for (int i = 0; i < bHap; i++) {
    cin >> c;
    b[c] = 1;
  }
  cin >> gHap;
  for (int i = 0; i < gHap; i++) {
    cin >> c;
    g[c] = 1;
  }
  for (int i = 0; i < n * m; i++) {
    b[i % n] = b[i % n] || g[i % m];
    g[i % m] = b[i % n] || g[i % m];
  }
  bool w = 1;
  for (int i = 0; i < n; i++) w &= b[i];
  for (int i = 0; i < m; i++) w &= g[i];
  if (w)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
