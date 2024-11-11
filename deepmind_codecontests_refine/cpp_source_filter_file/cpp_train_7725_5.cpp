#include <bits/stdc++.h>
using namespace std;
struct seq {
  int min;
  int max;
  bool itself;
};
bool operator<(const int value, const seq &s) { return value < s.max; }
seq si[100000];
int tmp[1000000];
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  int newcount = 0;
  int scount;
  cin >> scount;
  int len;
  for (int i = 0; i < scount; i++) {
    cin >> len;
    int value;
    int currmin = 1e7;
    int currmax = 0;
    for (int i = 0; i < len; i++) {
      cin >> value;
      tmp[i] = value;
      currmin = min(value, currmin);
      currmax = max(value, currmax);
    }
    si[newcount].max = currmax;
    si[newcount].min = currmin;
    if (len == 1) {
      si[newcount].itself = false;
      newcount++;
      continue;
    }
    int dp[len];
    dp[len - 1] = tmp[len - 1];
    int has = false;
    for (int i = len - 2; i >= 0; i--) {
      int cur = tmp[i];
      if (tmp[i] < dp[i + 1]) {
        has = true;
        break;
      }
      dp[i] = max(dp[i + 1], cur);
    }
    si[newcount].itself = has;
    if (!has) {
      si[newcount].itself = false;
      newcount++;
      continue;
    } else {
    }
  }
  std::sort(si, si + newcount,
            [](const seq &s1, const seq &s2) { return s1.max < s2.max; });
  long long result = 0;
  for (int i = 0; i < (scount - newcount); i++) {
    result += (2 * scount) - (2 * i) - 1;
  }
  for (int i = 0; i < newcount; i++) {
    if (si[i].itself) {
      result += scount;
      continue;
    }
    int currmin = si[i].min;
    int index = std::upper_bound(si, si + newcount, currmin) - si;
    int count = newcount - index;
    result += count;
  }
  printf("%d\n", result);
  return 0;
}
