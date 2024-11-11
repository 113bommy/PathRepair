#include <bits/stdc++.h>
using namespace std;
vector<int> zy[100010];
int sg[100010];
int ret[100010];
int main() {
  for (int i = 1; i <= 100000; ++i) {
    int sum = i;
    for (int j = i + 1; j <= 100000 && sum + j <= 100000; ++j) {
      sum += j;
      zy[sum].push_back(i);
      zy[sum].push_back(j);
    }
    sg[i] = 0;
  }
  for (int i = 3; i <= 100000; ++i) {
    int now = INT_MAX;
    set<int> ss;
    for (int j = 0; j < zy[i].size(); j += 2) {
      int low = zy[i][j];
      int high = zy[i][j + 1];
      int s = 0;
      for (int k = low; k <= high; ++k) {
        s ^= sg[k];
      }
      ss.insert(s);
      if (!s) {
        now = min(now, high - low + 1);
      }
    }
    if (now == INT_MAX) {
      sg[i] = 0;
    } else {
      int tp = 0;
      while (ss.count(tp)) {
        ++tp;
      }
      sg[i] = tp;
      ret[i] = now;
    }
  }
  int T = 100;
  while (T--) {
    int n;
    scanf("%d", &n);
    if (!sg[n]) {
      puts("-1");
    } else {
      printf("%d\n", ret[n]);
    }
  }
  return 0;
}
