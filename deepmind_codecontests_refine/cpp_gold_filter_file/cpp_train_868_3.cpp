#include <bits/stdc++.h>
using namespace std;
int n, m, ye, mo, da, ho, mi, se, cnt, date[20];
int ti[5000005];
char s[5000005];
const int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main() {
  for (int i = 1; i <= 12; i++) date[i] = date[i - 1] + days[i - 1];
  cin >> n >> m;
  gets(s);
  while (gets(s)) {
    sscanf(s, "%d-%d-%d %d:%d:%d", &ye, &mo, &da, &ho, &mi, &se);
    ti[cnt] = (date[mo] + da) * 86400 + ho * 3600 + mi * 60 + se;
    cnt++;
    s[19] = 0;
    if (cnt >= m && ti[cnt - 1] - ti[cnt - m] < n) {
      printf("%s\n", s);
      return 0;
    }
  }
  cout << -1;
}
