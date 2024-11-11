#include <bits/stdc++.h>
using namespace std;
int main() {
  string a;
  cin >> a;
  int cc = 0;
  vector<int> siz;
  siz.assign(a.length() + 2, 0);
  int n = a.length();
  vector<char> ty;
  ty.assign(n + 2, ' ');
  ty[0] = a[0];
  for (int i = 0; i < n - 1; i++) {
    siz[cc]++;
    if (a[i] != a[i + 1]) {
      cc++;
      ty[cc] = a[i + 1];
    }
    if (i == n - 2) siz[cc]++;
  }
  if (cc % 2 == 0) {
    int e = 1;
    for (int j = 0; j <= cc; j++) {
      if (ty[j] != ty[cc - j] || siz[j] + siz[cc - j] < 3) {
        e = 0;
      }
    }
    if (e)
      cout << siz[cc / 2] + 1 << endl;
    else
      cout << 0 << endl;
  } else
    cout << 0 << endl;
}
