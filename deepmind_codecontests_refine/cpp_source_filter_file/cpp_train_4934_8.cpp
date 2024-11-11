#include <bits/stdc++.h>
using namespace std;
int tab[3], d, m, y;
string s;
int valid[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int valid2[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool can;
int main() {
  cin >> s;
  can = false;
  d = (s[0] - '0') * 10 + (s[1] - '0');
  m = (s[3] - '0') * 10 + (s[4] - '0');
  y = (s[6] - '0') * 10 + (s[7] - '0');
  cin >> s;
  tab[0] = (s[0] - '0') * 10 + (s[1] - '0');
  tab[1] = (s[3] - '0') * 10 + (s[4] - '0');
  tab[2] = (s[6] - '0') * 10 + (s[7] - '0');
  do {
    if (tab[1] > 12) continue;
    if (tab[2] % 4 == 0)
      if (tab[0] > valid2[tab[1] - 1]) continue;
    if (tab[2] % 4 == 0)
      if (tab[0] > valid[tab[1] - 1]) continue;
    if (y - tab[2] < 18) continue;
    if (y - tab[2] > 18) can = true;
    if (m < tab[1]) continue;
    if (m > tab[1]) can = true;
    if (d >= tab[0]) can = true;
  } while (next_permutation(tab, tab + 3));
  if (can)
    cout << "YES";
  else
    cout << "NO";
  cout << endl;
  return 0;
}
