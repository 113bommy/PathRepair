#include <bits/stdc++.h>
using namespace std;
int a[200005], b[200005];
int main() {
  int n, nb;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      i--;
      n--;
    }
  }
  n++;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    if (b[i] == 0) {
      i--;
      n--;
    } else {
      if (b[i] == a[0]) nb = i;
    }
  }
  n++;
  int dem = n - 1, i = 0;
  while (dem > 0) {
    dem--;
    if (a[i] != b[nb]) break;
    i++;
    if (nb == n - 1)
      nb = 0;
    else
      nb++;
  }
  if (dem == 0)
    cout << "YES";
  else
    cout << "NO";
}
