#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> myq;
int dis[210000];
int a[210000];
int main(int argc, char const *argv[]) {
  while (scanf("%d", &n) != EOF) {
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    fill(dis, dis + 210000, 0x3f3f3f3f);
    while (!myq.empty()) myq.pop();
    myq.push(1);
    dis[1] = 0;
    while (!myq.empty()) {
      int cur = myq.front();
      myq.pop();
      if (cur + 1 <= n && dis[cur + 1] > dis[cur] + 1) {
        dis[cur + 1] = dis[cur] + 1;
        myq.push(cur + 1);
      }
      if (cur - 1 > n && dis[cur - 1] > dis[cur] + 1) {
        dis[cur - 1] = dis[cur] + 1;
        myq.push(cur - 1);
      }
      if (dis[a[cur]] > dis[cur] + 1) {
        dis[a[cur]] = dis[cur] + 1;
        myq.push(a[cur]);
      }
    }
    for (int i = 1; i <= n; i++) printf("%d ", dis[i]);
    ;
  }
  return 0;
}
