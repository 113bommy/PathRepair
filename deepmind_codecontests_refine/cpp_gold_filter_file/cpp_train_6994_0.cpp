#include <bits/stdc++.h>
using namespace std;
const int nmax = int(2e5) + 10;
string str1, str2;
int luck[] = {4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777};
int n, a[1010], sum, cnt, tt;
int main() {
  memset(a, 0, sizeof(a));
  for (int i = 0; i <= 14; i++)
    for (int j = 1; j <= 250; j++) {
      tt = j * luck[i];
      if (tt <= 1000)
        a[tt] = 1;
      else {
        break;
      }
    }
  while (cin >> n) {
    if (a[n])
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
