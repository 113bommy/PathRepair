#include <bits/stdc++.h>
using namespace std;
int n, q;
int a[5][100005];
void mo() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
}
void nhap() {
  cin >> n >> q;
  int yeuto = 0;
  for (int i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    if (a[u][v] == 0) {
      a[u][v] = 1;
      if (u == 1) {
        if (a[2][v] == 1) yeuto += 2;
        if (v > 1 && a[2][v - 1] == 1) yeuto += 2;
        if (v < n && a[2][v + 1] == 1) yeuto += 2;
      } else {
        if (a[1][v] == 1) yeuto += 2;
        if (v > 1 && a[1][v - 1] == 1) yeuto += 2;
        if (v < n && a[1][v + 1] == 1) yeuto += 2;
      }
    } else {
      a[u][v] = 0;
      if (u == 1) {
        if (a[2][v] == 1) yeuto -= 2;
        if (v > 1 && a[2][v - 1] == 1) yeuto -= 2;
        if (v < n && a[2][v + 1] == 1) yeuto -= 2;
      } else {
        if (a[1][v] == 1) yeuto -= 2;
        if (v > 1 && a[1][v - 1] == 1) yeuto -= 2;
        if (v < n && a[1][v + 1] == 1) yeuto -= 2;
      }
    }
    if (a[1][1] == 0 && a[2][n] == 0 && yeuto == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
int main() {
  mo();
  nhap();
}
