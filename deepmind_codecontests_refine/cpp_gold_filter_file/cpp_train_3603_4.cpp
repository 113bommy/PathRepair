#include <bits/stdc++.h>
using namespace std;
vector<int> limit, over;
int n, cnt, speed;
int main() {
  scanf("%d", &n);
  cnt = 0, speed = 0;
  limit.push_back(0x7fffffff);
  over.push_back(1);
  for (int i = 1; i <= n; ++i) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      scanf("%d", &speed);
      while (speed > limit.back()) cnt++, limit.pop_back();
    }
    if (type == 2)
      while (!over.back()) cnt++, over.pop_back();
    if (type == 3) {
      int lim;
      scanf("%d", &lim);
      if (lim < speed)
        cnt++;
      else
        limit.push_back(lim);
    }
    if (type == 4) over.push_back(1);
    if (type == 5) limit.push_back(0x7fffffff);
    if (type == 6) over.push_back(0);
  }
  printf("%d\n", cnt);
  return 0;
}
