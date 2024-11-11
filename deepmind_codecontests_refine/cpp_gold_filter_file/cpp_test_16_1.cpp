#include <bits/stdc++.h>
const int maxn = 2e5 + 9;
using namespace std;
pair<int, int> rr;
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    priority_queue<pair<int, int>> ss;
    for (int i = 0; i < n; i++) {
      scanf("%d", &rr.first);
      rr.second = i;
      ss.push(rr);
    }
    queue<pair<int, int>> qq;
    while (!ss.empty()) {
      pair<int, int> r1 = ss.top();
      ss.pop();
      pair<int, int> r2;
      if (!ss.empty()) {
        r2 = ss.top();
        ss.pop();
      } else {
        break;
      }
      if (r1.first > 0 && r2.first > 0) {
        r1.first--;
        r2.first--;
        qq.push({r1.second, r2.second});
      }
      if (r1.first > 0) {
        ss.push(r1);
      }
      if (r2.first > 0) {
        ss.push(r2);
      }
    }
    printf("%d\n", qq.size());
    while (!qq.empty()) {
      pair<int, int> rr = qq.front();
      qq.pop();
      printf("%d %d\n", rr.first + 1, rr.second + 1);
    }
  }
}
