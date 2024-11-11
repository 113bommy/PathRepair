#include <bits/stdc++.h>
using namespace std;
int n, x11, x12, y11, y12, x21, x22, y21, y22;
void tira(int &ans, int pri, int x1, int x2, int y1, int y2) {
  if (!pri) return;
  if (x1 <= x11 && x12 <= x2 && y1 <= y11 && y12 <= y2) ans--;
}
void calc(int pri) {
  int ini, fim, mid, esq = 1, dir = n, x1, x2, y1, y2;
  ini = 1, fim = n;
  while (ini <= fim) {
    mid = (ini + fim) >> 1;
    cout << '?' << " " << mid << " " << 1 << " " << n << " " << n << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    tira(ans, pri, mid, n, 1, n);
    if (ans > 0) {
      esq = mid;
      ini = mid + 1;
    } else
      fim = mid - 1;
  }
  x1 = esq;
  ini = esq, fim = n;
  while (ini <= fim) {
    mid = (ini + fim) >> 1;
    cout << '?' << " " << x1 << " " << 1 << " " << mid << " " << n << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    tira(ans, pri, x1, mid, 1, n);
    if (ans > 0) {
      dir = mid;
      fim = mid - 1;
    } else
      ini = mid + 1;
  }
  x2 = dir;
  esq = 1, dir = n;
  ini = 1, fim = n;
  while (ini <= fim) {
    mid = (ini + fim) >> 1;
    cout << '?' << " " << x1 << " " << mid << " " << x2 << " " << n << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    tira(ans, pri, x1, x2, mid, n);
    if (ans > 0) {
      esq = mid;
      ini = mid + 1;
    } else
      fim = mid - 1;
  }
  y1 = esq;
  ini = esq, fim = n;
  while (ini <= fim) {
    mid = (ini + fim) >> 1;
    cout << '?' << " " << x1 << " " << y1 << " " << x2 << " " << mid << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    tira(ans, pri, x1, x2, y1, n);
    if (ans > 0) {
      dir = mid;
      fim = mid - 1;
    } else
      ini = mid + 1;
  }
  y2 = dir;
  if (!pri)
    x11 = x1, x12 = x2, y11 = y1, y12 = y2;
  else
    x21 = x1, x22 = x2, y21 = y1, y22 = y2;
}
int main() {
  cin >> n;
  calc(0);
  calc(1);
  cout << "! " << x11 << " " << y11 << " " << x12 << " " << y12 << " " << x21
       << " " << y21 << " " << x22 << " " << y22 << endl;
}
