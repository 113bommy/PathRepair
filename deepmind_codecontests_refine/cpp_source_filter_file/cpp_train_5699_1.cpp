#include <bits/stdc++.h>
using namespace std;
int tab[6];
string s;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  for (int i = 0; i < 6; i++) {
    char a;
    cin >> a;
    switch (a) {
      case 'R':
        tab[0]++;
        break;
      case 'O':
        tab[1]++;
        break;
      case 'Y':
        tab[2]++;
        break;
      case 'G':
        tab[3]++;
        break;
      case 'B':
        tab[4]++;
        break;
      case 'V':
        tab[5]++;
    }
  }
  sort(tab, tab + 6);
  for (int i = 0; i < 6; i++) {
    s += (char)tab[i] + '0';
  }
  if (s == "000006" || s == "000015") cout << 1 << "\n";
  if (s == "000024" || s == "000033" || s == "000114") cout << 2 << "\n";
  if (s == "000123") cout << 2 << "\n";
  if (s == "001113") cout << 5 << "\n";
  if (s == "000222") cout << 10 << "\n";
  if (s == "001122") cout << 8 << "\n";
  if (s == "011112") cout << 15 << "\n";
  if (s == "111111") cout << 30 << "\n";
  return 0;
}
