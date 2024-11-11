#include <bits/stdc++.h>
using namespace std;
int n;
void solve(int ar[][2]) {
  if (n < 5) {
    cout << 0 << endl;
    return;
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int cont1(0), cont2(0), cont3(0), cont4(0);
    for (int k = 0; k < n; ++k) {
      if (ar[i][0] > ar[k][0] && ar[i][0 + 1] == ar[k][0 + 1] && i != k)
        cont1++;
      else if (ar[i][0] < ar[k][0] && ar[i][0 + 1] == ar[k][0 + 1] && i != k)
        cont2++;
      else if (ar[i][0 + 1] > ar[k][0 + 1] && ar[i][0] == ar[k][0] && i != k)
        cont3++;
      else if (ar[i][0 + 1] < ar[k][0 + 1] && ar[i][0] == ar[k][0] && i != k)
        cont4++;
    }
    if (cont1 > 0 && cont2 > 0 && cont3 > 0 && cont4 > 0) ans++;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  int points[n][2];
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 2; ++j) cin >> points[i][j];
  solve(points);
  return 0;
}
