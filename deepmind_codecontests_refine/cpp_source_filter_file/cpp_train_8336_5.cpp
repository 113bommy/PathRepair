#include <bits/stdc++.h>
using namespace std;
int num[120010];
map<int, int> m;
int main() {
  int po[31];
  int i, j, n;
  po[0] = 1;
  for (i = 1; i < 31; i++) po[i] = po[i - 1] * 2;
  while (scanf("%d", &n) != EOF) {
    m.clear();
    for (i = 0; i < n; i++) scanf("%d", &num[i]), m[num[i]]++;
    int count = 0;
    for (i = 0; i < n; i++) {
      int flag = 1;
      for (j = 1; j <= 30; j++) {
        if (num[i] <= po[j]) continue;
        int cha = po[j] - num[i];
        if (m[cha]) {
          if (cha == num[i]) {
            if (m[cha] >= 2) flag = 0;
          } else
            flag = 0;
        }
      }
      if (flag) count++;
    }
    printf("%d\n", count);
  }
  return 0;
}
