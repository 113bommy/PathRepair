#include <bits/stdc++.h>
using namespace std;
bool use[10];
char num[2000000];
int Nn, now, cnt;
char OAO[10][5] = {"1869", "6198", "1896", "1689", "1986",
                   "1968", "1698", "1869", "6198", "1896"};
int main() {
  scanf("%s", num);
  Nn = strlen(num);
  now = 0;
  for (int Ni = 0; Ni < Nn; Ni++) {
    if ((num[Ni] == '1' || num[Ni] == '6' || num[Ni] == '8' ||
         num[Ni] == '9') &&
        use[num[Ni] - '0'] == false) {
      use[num[Ni] - '0'] = true;
    } else if (num[Ni] - '0' == 0)
      cnt++;
    else {
      now *= 10;
      now += num[Ni] - '0';
      now %= 7;
      printf("%c", num[Ni]);
    }
  }
  printf("%s", OAO[now]);
  while (cnt--) {
    printf("0");
  }
  puts("");
}
