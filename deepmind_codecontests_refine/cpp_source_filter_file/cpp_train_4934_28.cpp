#include <bits/stdc++.h>
using namespace std;
struct da {
  int day;
  int mounth;
  int year;
} data[10];
int judge(da d) {
  if (d.mounth > 12) return 0;
  if ((d.mounth == 1 || d.mounth == 3 || d.mounth == 5 || d.mounth == 7 ||
       d.mounth == 8 || d.mounth == 10 || d.mounth == 12) &&
      d.day != 31)
    return 0;
  if ((d.mounth == 4 || d.mounth == 6 || d.mounth == 9 || d.mounth == 11) &&
      d.day != 30)
    return 0;
  if (d.mounth == 2) {
    if (d.day > 29) return 0;
    if (d.day == 29 && d.year % 4 != 0) return 0;
  }
  return 1;
}
int main() {
  da cc;
  char str[4], str1[4], str2[4], str3[1000];
  int i;
  while (scanf("%s", str3) != EOF) {
    str[0] = str3[0];
    str[1] = str3[1];
    str1[0] = str3[3];
    str1[1] = str3[4];
    str2[0] = str3[6];
    str2[1] = str3[7];
    cc.day = (str[0] - '0') * 10 + str[1] - '0';
    cc.mounth = (str1[0] - '0') * 10 + str1[1] - '0';
    cc.year = (str2[0] - '0') * 10 + str2[1] - '0';
    scanf("%s", str3);
    str[0] = str3[0];
    str[1] = str3[1];
    str1[0] = str3[3];
    str1[1] = str3[4];
    str2[0] = str3[6];
    str2[1] = str3[7];
    data[0].day = (str[0] - '0') * 10 + str[1] - '0';
    data[0].mounth = (str1[0] - '0') * 10 + str1[1] - '0';
    data[0].year = (str2[0] - '0') * 10 + str2[1] - '0';
    data[1].year = data[0].year;
    data[1].day = data[0].mounth;
    data[1].mounth = data[0].day;
    data[2].year = data[0].day;
    data[2].mounth = data[0].mounth;
    data[2].day = data[0].year;
    data[3].year = data[2].year;
    data[3].day = data[2].mounth;
    data[3].mounth = data[2].day;
    data[4].year = data[0].mounth;
    data[4].mounth = data[0].year;
    data[4].day = data[0].day;
    data[5].year = data[4].year;
    data[5].day = data[4].mounth;
    data[5].mounth = data[4].day;
    int flag = 0;
    for (i = 0; i < 6; i++) {
      if (!judge(data[i]) || cc.year - data[i].year < 18) {
        continue;
      } else {
        if (cc.year - data[i].year > 18) {
          flag = 1;
          break;
        } else {
          if (data[i].mounth < cc.mounth) {
            flag = 1;
            break;
          } else {
            if (data[i].mounth == cc.mounth && data[i].day <= cc.day) {
              flag = 1;
              break;
            }
          }
        }
      }
    }
    if (flag)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}
