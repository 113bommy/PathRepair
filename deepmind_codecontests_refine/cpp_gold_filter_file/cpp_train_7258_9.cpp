#include <bits/stdc++.h>
using namespace std;
pair<int, int> a[10], b[10];
int main() {
  for (int i = (1); i <= (4); ++i) scanf("%d%d", &a[i].first, &a[i].second);
  for (int i = (1); i <= (4); ++i) scanf("%d%d", &b[i].first, &b[i].second);
  sort(a + 1, a + 5);
  sort(b + 1, b + 5);
  for (int i = (b[2].second); i <= (b[3].second); ++i) {
    for (int j = (b[1].first + abs(b[1].second - i));
         j <= (b[4].first - abs(b[1].second - i)); ++j) {
      if (a[1].first <= j && j <= a[3].first && a[1].second <= i &&
          i <= a[2].second) {
        return puts("YES"), 0;
      }
    }
  }
  puts("NO");
}
