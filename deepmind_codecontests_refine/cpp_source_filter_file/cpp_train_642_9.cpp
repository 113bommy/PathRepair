#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
struct dat {
  int x;
  dat(int _x) : x(_x) {}
  bool operator<(const dat a) const { return x > a.x; }
};
int n, t;
long long ans;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    priority_queue<dat> q;
    vector<int> vt[n];
    for (int i = 1; i <= n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      vt[x].push_back(y);
    }
    int rest = n, d = 0;
    ans = 0;
    for (int i = n - 1; i >= 0; i--) {
      for (int j = 0; j < vt[i].size(); j++) {
        q.push(dat(vt[i][j]));
        rest--;
      }
      while (rest + d < i) {
        ans += (long long)q.top().x;
        q.pop();
        d++;
      }
    }
    printf("%d\n", ans);
  }
}
