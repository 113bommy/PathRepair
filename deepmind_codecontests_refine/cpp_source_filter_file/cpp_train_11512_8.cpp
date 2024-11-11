#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t[N];
int n = 0, k = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &t[i]);
  }
  int cur = 0, cnt = 0, res = 0;
  bool w = false, flag = true;
  for (int i = 1; i <= n; ++i) {
    if (t[i] >= 0) {
      ++cur;
      if (w) {
        res += 1;
        w = false;
      }
    } else {
      ++cnt;
      if (cur > 0) {
        if (!flag) {
          pq.push(make_pair(cur, -2));
        }
      }
      if (!w) {
        res += 1;
        w = true;
      }
      cur = 0;
      flag = false;
    }
  }
  if (cur) {
    pq.push(make_pair(cur, -1));
  }
  if (cnt > k) {
    printf("-1");
  } else {
    k -= cnt;
    while (!pq.empty()) {
      if (pq.top().first <= k) {
        k -= pq.top().first;
        res += pq.top().second;
        pq.pop();
      } else {
        break;
      }
    }
    if (!pq.empty() && cur > 0 && pq.top().first > cur &&
        pq.top().first <= cur + k) {
      --res;
    }
    printf("%d", res);
  }
  return 0;
}
