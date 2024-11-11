#include <bits/stdc++.h>
using namespace std;
bool com(char a, char b) { return a > b; }
int main() {
  string a, b;
  cin >> a >> b;
  int n = a.size();
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), com);
  int c = 0, i = 0, ni = n - 1, j = 0;
  char brr[n];
  int pos = n - 1, po = 0;
  ;
  while (c < n) {
    if (c % 2 == 0) {
      if (a[i] >= b[j]) {
        int jj = int(ceil((1.0 * (pos - po + 1)) / 2.0));
        ni = i + jj - 1;
        brr[pos] = a[ni];
        ni--;
        pos--;
      } else {
        brr[po] = a[i];
        i++;
        po++;
      }
    } else {
      if (a[i] > b[j]) {
        int jj = int(ceil((1.0 * (pos - po + 1)) / 2.0));
        ni = j + jj - 1;
        brr[pos] = b[ni];
        ni--;
        pos--;
      } else {
        brr[po] = b[j];
        j++;
        po++;
      }
    }
    c++;
  }
  for (int i = 0; i < n; i++) {
    cout << brr[i];
  }
  return 0;
}
