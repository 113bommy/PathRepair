#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:100000000")
int mas[110];
int main() {
  int n, m, x, y, c;
  memset(mas, 0, sizeof(mas));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> c;
    mas[x] -= c;
    mas[y] += c;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) ans += (mas[i] > 0) ? mas[i] : 0;
  cout << ans;
}
