#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[5001], t[3] = {}, c = 0, math[5000], m = 0, pro[5000], r = 0,
                  pp[5000], p = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      math[m] = i + 1;
      m++;
    } else if (a[i] == 2) {
      pro[r] = i + 1;
      r++;
    } else {
      pp[p] = i + 1;
      p++;
    }
    t[--a[i]]++;
  }
  for (int i = 0; i < n; i++)
    if (t[0] != 0 && t[1] != 0 && t[2] != 0) {
      c++;
      t[0]--;
      t[1]--;
      t[2]--;
    }
  cout << c << endl;
  for (int i = 0; i < c; i++) {
    cout << math[i] << " " << pro[i] << " " << pp[i] << endl;
  }
}
