#include <bits/stdc++.h>
using namespace std;
int n;
int dizi[1005];
int ca, cb;
int cont() {
  int cevap = 9999;
  for (int a = 0; a <= 10000; a++) {
    int t = dizi[0];
    int ealt = 9999, eust = -1;
    for (int i = 1; i < n; i++) {
      t += a;
      int ek = t - dizi[i];
      ealt = min(ek, ealt);
      eust = max(ek, eust);
    }
    if (cevap > (eust - ealt + 1) / 2) {
      cevap = (eust - ealt + 1) / 2;
      cb = a;
    }
  }
  return cevap;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> dizi[i];
  sort(dizi, dizi + n);
  int res = cont();
  cout << res << endl;
  for (int d = -10000; d <= 10000; d++) {
    bool y = true;
    int t = d;
    for (int i = 0; i < n; i++) {
      if (abs(t - dizi[i]) > res) {
        y = false;
        break;
      }
      t += cb;
    }
    if (y) {
      cout << d << " " << cb << endl;
      return 0;
    }
  }
  return 0;
}
