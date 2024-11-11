#include <bits/stdc++.h>
using namespace std;
int arr[3][100005];
int config;
int pn;
void check(int x, int y) {
  pn = arr[x][y] ? -1 : 1;
  config += pn * (arr[1 - x][y - 1] + arr[1 - x][y] + arr[1 - x][y + 1]);
  arr[x][y] ^= 1;
}
int main() {
  int n, q;
  cin >> n >> q;
  while (q--) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    check(x, y);
    cout << (config ? "No" : "Si") << endl;
  }
  return 0;
}
