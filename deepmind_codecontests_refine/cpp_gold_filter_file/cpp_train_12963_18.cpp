#include <bits/stdc++.h>
using namespace std;
struct nodes {
  int cnt[3];
} days[400];
int main(void) {
  int n;
  while (cin >> n) {
    for (int i = 1; i <= 366; i++) days[i].cnt[0] = days[i].cnt[1] = 0;
    for (int i = 0; i < n; i++) {
      char temp[5];
      int b, e, n;
      scanf("%s", temp);
      scanf("%d %d", &b, &e);
      if (temp[0] == 'M')
        n = 0;
      else
        n = 1;
      for (int j = b; j <= e; j++) days[j].cnt[n]++;
    }
    int mmax = 0;
    for (int i = 1; i <= 366; i++)
      mmax = max(min(days[i].cnt[0], days[i].cnt[1]), mmax);
    printf("%d\n", mmax * 2);
  }
  return 0;
}
