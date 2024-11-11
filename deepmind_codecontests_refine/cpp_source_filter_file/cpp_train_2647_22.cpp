#include <bits/stdc++.h>
using namespace std;
const int maxN = 100 * 1000 + 321;
int r[110];
int c[110];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    r[x] = 1;
    c[y] = 1;
  }
  int ansx = 0, ansy = 0;
  for (int i = 0; i < n; i++) {
    ansx += r[i];
    ansy += c[i];
  }
  cout << min(ansx, ansy) << endl;
  return 0;
}
