#include <bits/stdc++.h>
using namespace std;
int n, m;
int k;
bool debug = false;
char s[2005][2005];
bool bl[2005], bl1[2005], dia[2005];
int main() {
  scanf("%d", &n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    bool b = 0;
    for (int j = n - 1; j > i; j--) {
      if ((b ^ bl[j] && s[i][j] == '0') || (!(b ^ bl[j]) && s[i][j] == '1')) {
        ans++;
        b = !b;
        bl[j] = !bl[j];
        dia[j] = !dia[j];
        dia[i] = !dia[i];
      }
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    bool b = 0;
    for (int j = 0; j < i; j++) {
      if ((b ^ bl1[j] && s[i][j] == '0') || (!(b ^ bl1[j]) && s[i][j] == '1')) {
        ans++;
        b = !b;
        bl1[j] = !bl1[j];
        dia[j] = !dia[j];
        dia[i] = !dia[i];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if ((dia[i] && s[i][i] == '0') || (!dia[i] && s[i][i] == '1')) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
