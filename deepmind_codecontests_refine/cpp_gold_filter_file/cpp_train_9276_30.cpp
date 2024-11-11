#include <bits/stdc++.h>
using namespace std;
int n, i, j, o, w, k, m, l;
int mas[101][2];
bool s;
int main() {
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> k;
    for (j = 0; j < k; j++) {
      cin >> m;
      s = false;
      for (o = 0; o < l + 1; o++)
        if (m == mas[o][0]) {
          mas[o][1] += 1;
          s = true;
        }
      if (s == false) {
        mas[l][0] = m;
        mas[l][1] = 1;
        l += 1;
      }
    }
  }
  for (i = 0; i < l; i++)
    if (mas[i][1] == n) cout << mas[i][0] << " ";
  return 0;
}
