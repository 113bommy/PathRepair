#include <bits/stdc++.h>
using namespace std;
int n, m;
char s[5123456];
int main(int argc, char *argv[]) {
  scanf("%d%d", &n, &m);
  fgets(s, 5123456, stdin);
  vector<time_t> lgs;
  while (fgets(s, 5123456, stdin)) {
    tm shijian;
    shijian.tm_year = 2012 - 1900;
    shijian.tm_mon = ((s[5] - '0') * 10 + s[5 + 1] - '0') - 1;
    shijian.tm_mday = ((s[8] - '0') * 10 + s[8 + 1] - '0');
    shijian.tm_hour = ((s[11] - '0') * 10 + s[11 + 1] - '0');
    shijian.tm_min = ((s[14] - '0') * 10 + s[14 + 1] - '0');
    shijian.tm_sec = ((s[17] - '0') * 10 + s[17 + 1] - '0');
    lgs.push_back(mktime(&shijian));
  }
  time_t ans = 0;
  for (int i = 0; i + m - 1 < (int)lgs.size(); i++) {
    if (lgs[i + m - 1] - lgs[i] + 1 <= n) {
      ans = lgs[i + m - 1];
      break;
    }
  }
  if (ans == 0)
    cout << -1 << endl;
  else {
    tm *lt = localtime(&ans);
    printf("2012-%.2d-%.2d %.2d:%.2d:%.2d\n", lt->tm_mon + 1, lt->tm_mday,
           lt->tm_hour, lt->tm_min, lt->tm_sec);
  }
  return EXIT_SUCCESS;
}
