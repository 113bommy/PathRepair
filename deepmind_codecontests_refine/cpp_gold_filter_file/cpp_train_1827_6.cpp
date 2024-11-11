#include <bits/stdc++.h>
using namespace std;
int n;
int m;
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x = 2 * i + 1;
    int c = x + 2 * n;
    if (c <= m) cout << c << " ";
    c = x;
    if (c <= m) cout << c << " ";
    c = x + 1 + 2 * n;
    if (c <= m) cout << c << " ";
    c = x + 1;
    if (c <= m) cout << c << " ";
  }
  cout << endl;
}
