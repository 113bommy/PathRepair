#include <bits/stdc++.h>
using namespace std;
int i, j, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string arr[1010];
  string s;
  int lar[1010];
  int mayL, l;
  int n = 0;
  while (getline(cin, s) && n < 7) {
    arr[n] = s;
    lar[n] = s.length();
    mayL = max(lar[n], mayL);
    n++;
  }
  mayL += 2;
  for (i = 0; i < mayL; i++) cout << "*";
  cout << "\n";
  k = 0;
  j = 1;
  while (n--) {
    cout << "*";
    l = mayL - lar[k];
    if (l % 2 != 0) {
      if (j == 0) {
        l = l / 2;
        for (i = 1; i < l + 1; i++) cout << " ";
        cout << arr[k];
        for (i = 1; i < l; i++) cout << " ";
        j = 1;
      } else {
        l = l / 2;
        for (i = 1; i < l; i++) cout << " ";
        cout << arr[k];
        for (i = 1; i < l + 1; i++) cout << " ";
        j = 0;
      }
    } else {
      l = l / 2;
      for (i = 1; i < l; i++) cout << " ";
      cout << arr[k];
      for (i = 1; i < l; i++) cout << " ";
    }
    cout << "*"
         << "\n";
    k++;
  }
  for (i = 0; i < mayL; i++) cout << "*";
  return 0;
}
