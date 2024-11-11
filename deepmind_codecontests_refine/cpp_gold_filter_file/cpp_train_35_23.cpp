#include <bits/stdc++.h>
using namespace std;
char data[13], s[100006], sol[13];
int vmax, an, l, zi, val, maxi;
int main() {
  cin >> s;
  maxi = 0;
  for (an = 2013; an <= 2015; an++) {
    for (l = 1; l <= 12; l++) {
      int vmax;
      if (l == 1 || l == 3 || l == 5 || l == 7 || l == 8 || l == 10 || l == 12)
        vmax = 31;
      else {
        if (l == 2)
          vmax = 28;
        else
          vmax = 30;
      }
      for (zi = 1; zi <= vmax; zi++) {
        if (zi < 10) {
          data[0] = '0';
          data[1] = char('0' + zi);
        } else {
          data[0] = char(zi / 10 + '0');
          data[1] = char(zi % 10 + '0');
        }
        data[2] = '-';
        if (l < 10) {
          data[3] = '0';
          data[4] = char(l + '0');
        } else {
          data[3] = char(l / 10 + '0');
          data[4] = char(l % 10 + '0');
        }
        data[5] = '-';
        data[6] = char(an / 1000 + '0');
        data[7] = char(an / 100 % 10 + '0');
        data[8] = char(an / 10 % 10 + '0');
        data[9] = char(an % 10 + '0');
        val = 0;
        for (unsigned int i = 0; i < strlen(s) - 9; i++) {
          if (strncmp(s + i, data, 10) == 0) {
            val++;
            if (val > maxi) {
              maxi = val;
              strcpy(sol, data);
            }
          }
        }
      }
    }
  }
  cout << sol;
  return 0;
}
