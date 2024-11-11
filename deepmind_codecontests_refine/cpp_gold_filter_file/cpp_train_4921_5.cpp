#include <bits/stdc++.h>
const int MAX_N = 1000000;
int pref[1 + MAX_N + 1][2], suff[1 + MAX_N + 1][2];
void convolute(int i, int d, int &last, int &res) {
  int newlast = last;
  int newres = res;
  for (int join = 0; join < 2; ++join) {
    int expleft = pref[i][join], expright = suff[i + 1][join];
    if (expleft != 0 && expleft <= last) expleft = last + 1;
    if (expleft != 0 && i - expleft + 1 >= d) {
      if (res + 1 > newres) {
        newres = res + 1;
        newlast = expleft + d - 1;
      } else if (res + 1 == newres && expleft + d - 1 < newlast)
        newlast = expleft + d - 1;
    }
    if (expleft != 0 && expright != 0 && expright - expleft + 1 >= d) {
      if (res + 1 > newres) {
        newres = res + 1;
        newlast = expleft + d - 1;
      } else if (res + 1 == newres && expleft + d - 1 < newlast)
        newlast = expleft + d - 1;
    }
  }
  last = newlast;
  res = newres;
}
int main() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = "x" + str + 'x';
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 2; ++j)
      if ((str[i] == '0' + j || str[i] == '?')) {
        if (pref[i - 1][j] == 0)
          pref[i][j] = i;
        else
          pref[i][j] = pref[i - 1][j];
      }
  }
  for (int i = n; i > 0; --i) {
    for (int j = 0; j < 2; ++j)
      if ((str[i] == '0' + j || str[i] == '?')) {
        if (suff[i + 1][j] == 0)
          suff[i][j] = i;
        else
          suff[i][j] = suff[i + 1][j];
      }
  }
  for (int d = 1; d <= n; ++d) {
    int last = 0;
    int res = 0;
    for (int i = d; i <= n; i = i + d) convolute(i, d, last, res);
    convolute(n, d, last, res);
    printf("%d ", res);
  }
  return 0;
}
