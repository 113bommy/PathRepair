#include <bits/stdc++.h>
using namespace std;
struct str {
  long len;
  long shir;
};
struct str2 {
  long len;
  long shir;
  long val;
};
int main() {
  long n;
  cin >> n;
  vector<str> mass(n);
  long q;
  for (long i = 0; i < n; i++) {
    cin >> mass[i].shir;
    cin >> q;
    cin >> mass[i].len;
    mass[i].shir += q;
    mass[i].shir *= 2;
  }
  long m;
  cin >> m;
  long res = 0;
  vector<str2> mass2(m);
  for (long i = 0; i < m; i++)
    cin >> mass2[i].len >> mass2[i].shir >> mass2[i].val;
  long temp = 0, tt = 0, kol, kol2, koll;
  for (long i = 0; i < n; i++) {
    temp = 100000;
    for (long j = 0; j < m; j++) {
      kol = mass2[j].len / mass[i].len;
      if (kol > 0) {
        kol2 = mass[i].shir / mass2[j].shir;
        if (mass[i].shir % mass2[j].shir != 0) kol2++;
        koll = kol2 / kol;
        if (kol2 % kol != 0) koll++;
        temp = min((long)temp, (long)(koll * mass2[j].val));
      }
    }
    res += temp;
  }
  cout << res;
}
