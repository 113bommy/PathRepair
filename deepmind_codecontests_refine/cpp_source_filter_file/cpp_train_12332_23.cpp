#include <bits/stdc++.h>
using namespace std;
int main() {
  int ns, nm, nl, nxl, nxxl, k, i;
  char a[1000][5];
  cin >> ns >> nm >> nl >> nxl >> nxxl;
  cin >> k;
  for (i = 0; i < k; i++) cin >> a[i];
  for (i = 0; i < k; i++) {
    if (a[i][0] == 'S') {
      if (ns > 0) {
        cout << "S\n";
        ns--;
      } else if (nm > 0) {
        cout << "M\n";
        nm--;
      } else if (nl > 0) {
        cout << "L\n";
        nl--;
      } else if (nxl > 0) {
        cout << "XL\n";
        nxl--;
      } else if (nxxl > 0) {
        cout << "XXL\n";
        nxxl--;
      }
    }
    if (a[i][0] == 'M') {
      if (nm > 0) {
        cout << "M\n";
        nm--;
      } else if (nl > 0) {
        cout << "L\n";
        nl--;
      } else if (ns > 0) {
        cout << "S\n";
        ns--;
      } else if (nxxl > 0) {
        cout << "XXL\n";
        nxxl--;
      } else if (nxl > 0) {
        cout << "XL\n";
        nxl--;
      }
    }
    if (a[i][0] == 'L') {
      if (nl > 0) {
        cout << "L\n";
        nl--;
      } else if (nxl > 0) {
        cout << "XL\n";
        nxl--;
      } else if (nm > 0) {
        cout << "M\n";
        nm--;
      } else if (nxxl > 0) {
        cout << "XXL\n";
        nxxl--;
      } else if (ns > 0) {
        cout << "S\n";
        ns--;
      }
    }
    if (a[i][0] == 'X' && a[i][1] == 'L') {
      if (nxl > 0) {
        cout << "XL\n";
        nxl--;
      } else if (nxxl > 0) {
        cout << "XXL\n";
        nxxl--;
      } else if (nl > 0) {
        cout << "L\n";
        nl--;
      } else if (nm > 0) {
        cout << "M\n";
        nm--;
      } else if (ns > 0) {
        cout << "S\n";
        ns--;
      }
    }
    if (a[i][0] == 'X' && a[i][1] == 'X' && a[i][2] == 'L') {
      if (nxxl > 0) {
        cout << "XXL\n";
        nxxl--;
      } else if (nxl > 0) {
        cout << "XL\n";
        nxl--;
      } else if (nl > 0) {
        cout << "L\n";
        nl--;
      } else if (nm > 0) {
        cout << "M\n";
        nm--;
      } else if (ns > 0) {
        cout << "S\n";
        ns--;
      }
    }
  }
}
