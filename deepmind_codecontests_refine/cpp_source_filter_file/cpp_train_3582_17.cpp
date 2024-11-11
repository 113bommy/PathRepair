#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:100000000000,100000000000")
using namespace std;
const long long inf = 1e18 + 7;
const long long mod = 1e9 + 7;
const double eps = 1e-12;
const double PI = 2 * acos(0.0);
const double E = 2.71828;
vector<int> cnt[205];
int num[205];
int ans[205];
int main(void) {
  int n;
  scanf("%d", &n);
  n *= 2;
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    int x;
    scanf("%d", &x);
    cnt[x].push_back(i);
    num[i] = x;
  }
  int x = 0;
  int canUse = 0;
  for (long long(i) = 0; (i) < (long long)(105); (i)++) {
    if (cnt[i].size() >= 2) {
      ++x;
      ans[cnt[i][0]] = 1;
      for (int j = 1; j < cnt[i].size(); ++j) {
        ans[cnt[i][j]] = 2;
      }
    } else {
      canUse += (int)cnt[i].size();
    }
  }
  int needInFirst = 0;
  for (int i = 0; i <= min(canUse, n / 2 - x); ++i) {
    if ((needInFirst + x) * (canUse - needInFirst + x) <
        (i + x) * (canUse - i + x)) {
      needInFirst = i;
    }
  }
  printf("%d\n", (needInFirst + x) * (canUse - needInFirst + x));
  int req = n / 2 - needInFirst - x;
  for (long long(i) = 0; (i) < (long long)(105); (i)++) {
    if (cnt[i].size() == 1) {
      if (needInFirst > 0) {
        --needInFirst;
        ans[cnt[i][0]] = 1;
      } else {
        ans[cnt[i][0]] = 2;
      }
    } else if (cnt[i].size() == 2) {
      for (int j = 1; j < cnt[i].size(); ++j) {
        if (req) {
          ans[cnt[i][j]] = 1;
          req--;
        }
      }
    }
  }
  for (long long(i) = 0; (i) < (long long)(n); (i)++) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}
