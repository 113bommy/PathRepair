#include <bits/stdc++.h>
using namespace std;
int n, dlkodu, p;
string wyrazy[100010], kod;
int sprawdz(int p, int k) {
  int dl = wyrazy[k].length();
  for (int i = 0; i < dl; i++) {
    while (p < dlkodu && kod[p] != wyrazy[k][i]) p++;
    if (p == dlkodu) return 0;
    p++;
  }
  return p;
}
int main() {
  wyrazy[0] = "<3";
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> wyrazy[i];
  cin >> kod;
  dlkodu = kod.length();
  p = sprawdz(0, 0);
  if (p == 0) {
    cout << "no";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    p = sprawdz(p, i);
    if (p == 0) {
      cout << "no";
      return 0;
    }
    p = sprawdz(p, 0);
    if (p == 0) {
      cout << "no";
      return 0;
    }
  }
  cout << "yes";
  return 0;
}
