#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[10];
  for (int i = 1; i <= 9; i++) cin >> a[i];
  int minn = 9999999;
  int cifra = 0;
  for (int i = 9; i > 0; i--) {
    if (a[i] < minn) {
      cifra = i;
      minn = a[i];
    }
  }
  if (n < minn) {
    cout << "-1" << endl;
    return 0;
  }
  int len = n / minn;
  int broj[len];
  for (int i = 0; i < len; i++) broj[i] = cifra;
  for (int i = 0; i < len; i++) {
    broj[i] = cifra;
  }
  int ostalo = n - len * a[cifra];
  for (int i = 0; i < len; i++)
    for (int j = 9; j > cifra; j--) {
      if (a[j] - a[cifra] < ostalo) {
        ostalo - (a[j] - a[cifra]);
        broj[i] = j;
        break;
      }
    }
  for (int i = 0; i < len; i++) {
    cout << broj[i];
  }
  cout << endl;
  return 0;
}
