#include <bits/stdc++.h>
int main() {
  int n, m, d, v;
  int result[300000];
  std::map<int, int> myMap;
  std::map<int, int>::iterator itlow;
  while (scanf("%d%d%d", &n, &m, &d) == 3) {
    for (int i = 0; i < n; i++) {
      scanf("%d", &v);
      myMap.insert(std::pair<int, int>(v, i));
    }
    int day;
    for (day = 1; myMap.empty() == false; day++) {
      for (int j = 1; j <= m;) {
        itlow = myMap.lower_bound(j);
        if (itlow != myMap.end()) {
          result[itlow->second] = day;
          j = itlow->first + d + 1;
          myMap.erase(itlow);
        }
        j = m + 1;
      }
    }
    printf("%d\n", day - 1);
    for (int j = 0; j < n; j++) printf("%d ", result[j]);
    printf("\n");
  }
  return 0;
}
