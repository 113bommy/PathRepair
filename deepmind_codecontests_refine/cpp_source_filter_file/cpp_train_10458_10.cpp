#include <bits/stdc++.h>
using namespace std;
int a[10], cnt[10], c[10];
;
int main() {
  while (scanf("%d", &a[1]) != EOF) {
    memset(cnt, 0, sizeof(cnt));
    cnt[a[1]] = 1;
    for (int i = 2; i <= 6; i++) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    sort(a + 1, a + 6 + 1);
    int len = unique(a + 1, a + 6 + 1) - a - 1;
    int flag = 0;
    for (int i = 1; i <= 6; i++) {
      if (cnt[a[i]] == 4) {
        flag = 1;
        break;
      } else if (cnt[a[i]] == 5) {
        flag = 2;
        break;
      } else if (cnt[a[i]] = 6) {
        flag = 3;
        break;
      }
    }
    if ((flag == 1) && len == 3 || (flag == 2)) {
      cout << "Bear" << endl;
    } else if ((flag == 1) && (len == 2) || flag == 3) {
      cout << "Elephant" << endl;
    } else
      cout << "Alien" << endl;
  }
  return 0;
}
