#include <bits/stdc++.h>
using namespace std;
struct tt {
  int x, w, t;
  bool operator<(const tt& p) const { return w < p.w; }
} given[2100];
bool cmp(const tt& a, const tt& b) { return a.x < b.x; }
vector<tt> arr[2100];
priority_queue<tt> pq[2];
int main() {
  int n, x;
  scanf("%d %d", &n, &x);
  for (int i = 0; i < n; ++i) {
    scanf("%d %d %d", &given[i].t, &given[i].x, &given[i].w);
  }
  int save = x;
  for (int i = 0; i < n; ++i) {
    if (given[i].x <= x) {
      pq[given[i].t].push(given[i]);
    }
  }
  int prv = 0;
  int cnt = 0;
  while (true) {
    if (pq[!prv].empty())
      break;
    else {
      tt ff = pq[!prv].top();
      pq[!prv].pop();
      for (int i = 0; i < n; ++i) {
        if (given[i].x > x && given[i].x <= x + ff.w) {
          pq[given[i].t].push(given[i]);
        }
      }
      x += ff.w;
      cnt++;
      prv = !prv;
    }
  }
  while (!pq[0].empty()) pq[0].pop();
  while (!pq[1].empty()) pq[1].pop();
  x = save;
  for (int i = 0; i < n; ++i) {
    if (given[i].x <= x) {
      pq[given[i].t].push(given[i]);
    }
  }
  prv = 1;
  int cnt2 = 0;
  while (true) {
    if (pq[!prv].empty())
      break;
    else {
      tt ff = pq[!prv].top();
      pq[!prv].pop();
      for (int i = 0; i < n; ++i) {
        if (given[i].x > x && given[i].x <= x + ff.w) {
          pq[given[i].t].push(given[i]);
        }
      }
      x += ff.w;
      cnt2++;
      prv = !prv;
    }
  }
  printf("%d\n", max(cnt, cnt2));
  return 0;
}
