#include <bits/stdc++.h>
using namespace std;
int n, m, k[110], c[110], hm[110];
bool tf;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 1; i <= m; i++) cin >> k[i];
  for (int i = 0; i < n; i++) {
    for (int i2 = i; i2 < n; i2++) {
      for (int i3 = 0; i3 < 110; i3++) hm[i3] = 0;
      tf = true;
      for (int i3 = i; i3 <= i2; i3++) hm[c[i3]]++;
      for (int i3 = 1; i3 <= m; i3++) {
        if (hm[i3] != k[i3]) tf = false;
      }
      if (tf) {
        cout << "Yes";
        return 0;
      }
    }
  }
  cout << "No";
  return 0;
}
